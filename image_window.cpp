#include "wx/dcbuffer.h"
#include "wx/settings.h"

#include "app/image_window.h"
#include "app/main_frame.h"
#include "app/dnd_file.h"

BEGIN_EVENT_TABLE(ImageWindow, wxScrolledWindow)
EVT_RIGHT_DOWN(ImageWindow::OnRightClicked)
EVT_PAINT(ImageWindow::OnPaint)
EVT_ERASE_BACKGROUND(ImageWindow::OnEraseBackground)
EVT_SIZE(ImageWindow::OnSize)
EVT_LEFT_DCLICK(ImageWindow::OnLeftDclick)
EVT_KEY_DOWN(ImageWindow::OnEscapeKeyDown)
END_EVENT_TABLE()

ImageWindow::ImageWindow(wxWindow* parent, wxWindowID winid, const wxPoint& mypoint, 
                         const wxSize& mysize, const wxImage& image)
    : wxScrolledWindow(parent, winid, mypoint, mysize, wxVSCROLL | wxHSCROLL)
    , image_(image)
    , child_frame_((wxFrame*)parent) {
}

ImageWindow::ImageWindow(wxWindow* parent, wxWindowID winid, const wxPoint& mypoint, const wxSize& mysize)
    : wxScrolledWindow(parent, winid, mypoint, mysize, wxVSCROLL | wxHSCROLL){
}

ImageWindow::~ImageWindow() {
}

void ImageWindow::OnRightClicked(wxMouseEvent& event) {
  wxMenu* menu = new wxMenu;

  menu->Append(wxID_OPEN, "&Open");
  menu->Append(wxID_SAVE, "&Save");
  menu->Append(wxID_COPY, "&Copy");
  menu->Append(wxID_PASTE, "&Paste");
  menu->Enable(wxID_PASTE, false);
  menu->Enable(wxID_COPY, false);
  menu->AppendSeparator();
  menu->Append(wxID_EXIT, "&Exit");

  PopupMenu(menu, event.GetPosition());
}

void ImageWindow::OnPaint(wxPaintEvent& event) {
  wxBufferedPaintDC dc(this);
  PrepareDC(dc);
  dc.Clear();
  Draw(dc);
}

void ImageWindow::Draw(wxDC& dc) {
  wxBitmap bitmap = image_copy_;
  wxCoord xpos = ((double)client_size_.x - update_image_width_) / 2;
  wxCoord ypos = ((double)client_size_.y - update_image_height_) / 2;
  dc.DrawBitmap(bitmap, xpos, ypos);
}

void ImageWindow::OnEraseBackground(wxEraseEvent& event) {
}

void ImageWindow::OnSize(wxSizeEvent& event) {
  client_size_ = GetClientSize();

  double scale_x = ((double)client_size_.x) / ((double)image_.GetWidth());
  double scale_y = ((double)client_size_.y) / ((double)image_.GetHeight());
  double scale = wxMin(scale_x, scale_y);

  int new_width = (int)(scale * image_.GetWidth());
  int new_height = (int)(scale* image_.GetHeight());

  image_copy_ = image_.Scale(new_width, new_height);
  update_image_width_ = (double)image_copy_.GetWidth();
  update_image_height_ = (double)image_copy_.GetHeight();

  Refresh();
}

void ImageWindow::OnLeftDclick(wxMouseEvent& event) {
  child_frame_->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxSYSTEM_MENU | wxRESIZE_BORDER | wxMAXIMIZE_BOX | 
                               wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN));
  child_frame_->Maximize(true);
  child_frame_->SetBackgroundColour(wxNullColour);
  Refresh(true);
}

void ImageWindow::OnEscapeKeyDown(wxKeyEvent& event) {
  if (event.GetUnicodeKey() == WXK_ESCAPE) {
    child_frame_->Maximize(false);
    child_frame_->SetWindowStyle(wxCAPTION | wxRESIZE_BORDER | wxCLOSE_BOX);
  }
}
