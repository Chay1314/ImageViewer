#ifndef IMAGEVIEWER_APP_IMAGE_WINDOW_H_
#define IMAGEVIEWER_APP_IMAGE_WINDOW_H_

#include "wx/scrolwin.h"
#include "wx/menu.h"
#include "app/main_frame.h"


class ImageWindow : public wxScrolledWindow {
  DECLARE_EVENT_TABLE();

public:
  ImageWindow(wxWindow* parent, wxWindowID winid, const wxPoint& mypoint,
              const wxSize& mysize, const wxImage& image);
  ImageWindow(wxWindow* parent, wxWindowID winid, const wxPoint& mypoint, const wxSize& mysize);

  virtual ~ImageWindow();

  void OnRightClicked(wxMouseEvent& event);
  void OnEraseBackground(wxEraseEvent& event);
  void OnPaint(wxPaintEvent& event);
  void Draw(wxDC& dc);
  void OnSize(wxSizeEvent& event);
  void OnLeftDclick(wxMouseEvent& event);
  void OnEscapeKeyDown(wxKeyEvent& event);

private:
  wxImage image_;
  wxImage image_copy_;
  wxSize client_size_;
  double update_image_width_;
  double update_image_height_;
  MainFrame* max_window_;
  wxFrame* child_frame_;
};

#endif  // IMAGEVIEWER_APP_IMAGE_WINDOW_H_
