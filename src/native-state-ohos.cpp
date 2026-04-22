/*
 * Copyright © 2025 Collabora Ltd
 *
 * This file is part of the glmark2 OpenGL (ES) 2.0 benchmark.
 *
 * glmark2 is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * glmark2 is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * glmark2.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "native-state-ohos.h"
#include "log.h"

extern void *g_window;

bool
NativeStateOHOS::init_display()
{
    return true;
}

void*
NativeStateOHOS::display()
{
    return nullptr;
}

bool
NativeStateOHOS::create_window(WindowProperties const& properties)
{
    if (properties.fullscreen) {
        Log::error("Fullscreen not supported\n");
        return false;
    }

    if (properties.width <= 0 || properties.height <= 0) {
        Log::error("Invalid surface size\n");
        return false;
    }
    properties_ = properties;

    return true;
}

void*
NativeStateOHOS::window(WindowProperties& properties)
{
    properties = properties_;    
    return g_window;
}

void
NativeStateOHOS::visible(bool v)
{
}

bool
NativeStateOHOS::should_quit()
{
    return false;
}

void
NativeStateOHOS::flip()
{
}
