#ifndef __HEATER_COMM__H__
#define __HEATER_COMM__H__

enum HeaterStatus { POSITIVE, NEGATIVE, ALTERNATIVE, ZERO };


class HeaterComm{
  public:
    HeaterComm();
    HeaterStatus status;

    void setStatus(HeaterStatus value);
};

#endif
