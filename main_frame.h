#ifndef IMAGEVIEWER_APP_MAIN_FRAME_H_
#define IMAGEVIEWER_APP_MAIN_FRAME_H_

#include <map>

#include "wx/sizer.h"
#include "wx/scrolwin.h"
#include "wx/frame.h"
#include "wx/statbmp.h"
#include "wx/filedlg.h"
#include "wx/dnd.h"

class wxImage;

class MainFrame : public wxFrame {
  DECLARE_EVENT_TABLE();

  friend class ImageWindow;

public:
  // TODO: Use wxPoint and wxSize as parameters.
  // TODO: Use const wxString& instead of const wxChar* for title.
  MainFrame(const wxString& title, const wxPoint& mypoint, const wxSize& mysize);
  virtual ~MainFrame();

  void OnMenuFileQuit(wxCommandEvent& event);
  void OnMenuInfoAbout(wxCommandEvent& event);
  void OnMenuOptionDirectory(wxCommandEvent& event);
  void OnPictureFileOpen(wxCommandEvent& event);
  void OnLoadImageThread(wxThreadEvent& event);

private:
  enum {
    ID_MENU_INFO_ABOUT = wxID_HIGHEST + 100,
    ID_MENU_BACKGROUND_COLOUR,
    ID_MENU_SELECT_DIRECTORY
  };

  ImageWindow* image_window_;
  wxFrame* child_frame_;
  std::map<wxString, wxImage> images_map_;
};

#endif  // IMAGEVIEWER_APP_MAIN_FRAME_H_
