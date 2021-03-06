/*
 * Desktop.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#import <Cocoa/Cocoa.h>

#include <LLGL/Desktop.h>


namespace LLGL
{

namespace Desktop
{


LLGL_EXPORT Size GetResolution()
{
    /* Get pixel size from main display */
    CGDirectDisplayID display = CGMainDisplayID();
    return Size(
        static_cast<int>(CGDisplayPixelsWide(display)),
        static_cast<int>(CGDisplayPixelsHigh(display))
    );
}

LLGL_EXPORT int GetColorDepth()
{
    return 24;
}

LLGL_EXPORT bool SetVideoMode(const VideoModeDescriptor& videoMode)
{
    /*if (videoMode.fullscreen)
        [[NSApplication sharedApplication] setPresentationOptions:NSFullScreenWindowMask];
    else
        ;*/
    return false;
}

LLGL_EXPORT bool ResetVideoMode()
{
    return false;
}


} // /namespace Desktop

} // /namespace LLGL



// ================================================================================
