#ifndef IMAGEVIEWER_APP_APP_H_
#define IMAGEVIEWER_APP_APP_H_

#include "wx/app.h"

class App : public wxApp {
public:
  virtual bool OnInit() override;
};

DECLARE_APP(App)

#endif  // IMAGEVIEWER_APP_APP_H_
