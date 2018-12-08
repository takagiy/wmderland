#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <string>
#include <vector>

enum Direction {
    HORIZONTAL,
    VERTICAL
};

enum Action {
    TILE_H,
    TILE_V,
    FOCUS_LEFT,
    FOCUS_RIGHT,
    FOCUS_DOWN,
    FOCUS_UP,
    TOGGLE_FLOATING,
    TOGGLE_FULLSCREEN,
    KILL,
    EXIT,
    EXEC,
    UNDEFINED
};

struct WindowPosSize {
    WindowPosSize();
    WindowPosSize(int x, int y, int width, int height);

    int x, y;
    int width, height;
};

namespace wm_utils {
    std::pair<short, short> GetDisplayResolution(Display* dpy, Window root);
    XWindowAttributes QueryWindowAttributes(Display* dpy, Window w);
    XSizeHints QueryWmNormalHints(Display* dpy, Window w);
    XClassHint QueryWmClass(Display* dpy, Window w);

    unsigned int QueryKeycode(Display* dpy, const std::string& key_name);
    std::string QueryKeysym(Display* dpy, unsigned int keycode, bool shift);
    std::string KeymaskToStr(int modifier);
    int StrToKeymask(const std::string& modifier_str, bool shift);
    Action StrToAction(const std::string& action_str);
    
    bool IsDialogOrNotification(Display* dpy, Window w, Atom* atoms);
    bool IsBar(Display* dpy, Window w);
}

namespace string_utils {
    std::vector<std::string> Split(const std::string& s, const char delimiter);
    std::vector<std::string> Split(const std::string& s, const char delimiter, short count);
    bool StartsWith(const std::string& s, const std::string& keyword);
    bool Contains(const std::string& s, const std::string& keyword);
    void Replace(std::string& s, const std::string keyword, const std::string newword);
    void Trim(std::string& s);
    std::string ToAbsPath(const std::string& path);
}

#endif
