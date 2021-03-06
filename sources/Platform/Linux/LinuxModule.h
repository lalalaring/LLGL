/*
 * LinuxModule.h
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_LINUX_MODULE_H
#define LLGL_LINUX_MODULE_H


#include "../Module.h"


namespace LLGL
{


class LinuxModule : public Module
{

    public:

        LinuxModule(const std::string& moduleFilename);
        ~LinuxModule();

        LinuxModule(const LinuxModule&) = delete;
        LinuxModule& operator = (const LinuxModule&) = delete;

        void* LoadProcedure(const std::string& procedureName) override;

    private:

        void* handle_ = nullptr;

};


} // /namespace LLGL


#endif



// ================================================================================
