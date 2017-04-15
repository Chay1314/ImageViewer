#include "app/app.h"
#include "app/main_frame.h"
#include "app/config.h"

IMPLEMENT_APP(App)

bool App::OnInit() {
  if (!wxApp::OnInit()) {
    return false;
  }
  wxInitAllImageHandlers();

  ConfigFile* config_file = new ConfigFile();
  if (!config_file->read()) {
    wxLogMessage("CONFIG FILE NOT FOUND!");
    MainFrame* image_frame = new MainFrame(_T("Image Viewer"), wxPoint(200, 100), wxSize(700, 450));
    wxIcon icon1("w9.ico", wxBITMAP_TYPE_ICO, 16, 16);
    image_frame->SetIcon(icon1);
    image_frame->Show(true);
    return true;
  }

  MainFrame* image_frame = new MainFrame(_T("Image Viewer"), config_file->get_point(), config_file->get_size());
  wxIcon icon1("w9.ico", wxBITMAP_TYPE_ICO, 16, 16);
  image_frame->SetIcon(icon1);
  image_frame->Show(true);
  return true;
}
