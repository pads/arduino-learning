var five = require('johnny-five');
var board = new five.Board();

board.on('ready', function () {
  var lcd = new five.LCD({
    pins: [12, 11, 5, 4, 3, 2],
    rows: 2,
    cols: 16
  });

  var temperatureSensor = new five.Sensor({
    pin: 'A0',
    freq: 1000
  });
  var lightSensor = new five.Sensor({
    pin: 'A1',
    freq: 1000
  });

  board.repl.inject({
    temperatureSensor: temperatureSensor,
    lightSensor: lightSensor
  });

  lcd.on('ready', function () {
    var temperatureInCelcius = 0;
    var lightReading = 0;

    // Start on the first row
    lcd.print('Temp :      C');

    temperatureSensor.on('data', function () {
      var temperatureReading = this.value;
      var temperatureInVolts = (temperatureReading / 1024.0) * 5.0;
      temperatureInCelcius = ((temperatureInVolts - 0.5) * 100).toFixed(3);

      // Jump 6 columns
      lcd.setCursor(6, 0);
      lcd.print(temperatureInCelcius);
    });

    lightSensor.on('data', function () {
      lightReading = this.value;

      // Jump to the next row
      lcd.setCursor(0, 1);
      lcd.print('Light:           ');
      lcd.setCursor(6, 1);
      lcd.print(lightReading);
    });
  });
});
