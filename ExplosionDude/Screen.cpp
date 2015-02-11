#include "Screen.h"

Screen::Screen()
{
    m_screenLoc=0;
}

bool Screen::Init(int w, int h, unsigned int flag)
{
    m_screenLoc=SDL_SetVideoMode(w,h,0,flag);
    SDL_WM_SetCaption("bloopy",NULL);
    m_screenWidth=w;
    m_screenHeight=h;
    m_flag=flag;
    return (m_screenLoc!=0);
    //m_screen==0? return false:return true
}

void Screen::Clear()
{
    SDL_FillRect( SDL_GetVideoSurface(), NULL, 0 );
}

SDL_Surface*Screen::GetScreen() const
{
    return m_screenLoc;
}

void Screen::Flip()
{
    SDL_Flip(m_screenLoc);
}

Vec2<int> Screen::ScreenBounds()
{
    Vec2<int> temp(m_screenWidth,m_screenHeight);
    return temp;
}

