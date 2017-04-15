#ifndef IMAGEVIEWER_APP_CONFIG_H_
#define IMAGEVIEWER_APP_CONFIG_H_

#include "app/main_frame.h"

class ConfigFile {
public:
  ConfigFile();
  void wirte();
  bool read();

  wxPoint get_point() const;
  wxSize get_size() const;

private:
  wxPoint win_position_;
  wxSize win_size_;
};

#endif  // IMAGEVIEWER_APP_CONFIG_H_
