# Heater command

Arduino program for Wemos (ESP8266) to control electric heater


## First  use

- Push WPS button on your box
- Switch on the Wemos
- Wait

If 2 blinks on D4 => fail
If 4 blinks on D4 => success

## Connect

- D4 => led
- D1 => positive part of the 230V sinusoide
- D2 => negative part of the 230V sinusoide

## API

### GET /status

json status

```json
{
    "status": "zero"
}
```

### POST /status

Body in plain text `zero`, `positive`, `negative`, `alternative`