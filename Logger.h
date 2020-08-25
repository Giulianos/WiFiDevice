#ifndef LOGGER_H_
#define LOGGER_H_

class Logger {
  bool _enabled;
  String _context;

public:
  Logger(String context) {
    _context = context;
  }

  void println(String msg) {
    if (_enabled) {
      Serial.println(_context + ": " + msg);  
    }
  }
  
  void setEnabled(bool enabled) {
    _enabled = enabled;
  }
};

#endif
