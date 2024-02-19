/* cc -lX11 -lxkbfile getlayout.c */

#include <stdio.h>
#include <string.h>

#include <X11/XKBlib.h>
#include <X11/extensions/XKBrules.h>

int main(void)
{
    Display *dpy = XOpenDisplay(NULL);

    if (dpy == NULL)
    {
        fputs("Cannot open display\n", stderr);
        return 1;
    }

    XkbStateRec state;
    XkbGetState(dpy, XkbUseCoreKbd, &state);

    XkbRF_VarDefsRec vd;
    XkbRF_GetNamesProp(dpy, NULL, &vd);

    char *tok = strtok(vd.layout, ",");

    for (int i = 0; i < state.group; i++)
    {
        tok = strtok(NULL, ",");
        if (tok == NULL)
            return 1;
    }

    fputs(tok, stdout);
}
