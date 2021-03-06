/*
 * RenderTarget.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include <LLGL/RenderTarget.h>
#include <LLGL/Texture.h>
#include <Gauss/Equals.h>
#include <stdexcept>
#include <string>


namespace LLGL
{


RenderTarget::~RenderTarget()
{
}


/*
 * ======= Protected: =======
 */

static std::string ResToStr(const Gs::Vector2ui& res)
{
    return std::to_string(res.x) + 'x' + std::to_string(res.y);
}

void RenderTarget::ApplyResolution(const Gs::Vector2ui& resolution)
{
    /* Validate texture attachment size */
    if (resolution == Gs::Vector2ui(0, 0))
    {
        throw std::invalid_argument("attachment to render target failed, due to invalid size of zero");
    }

    /* Check if size matches the current resolution */
    if (resolution_ != Gs::Vector2ui(0, 0))
    {
        if (resolution != resolution_)
        {
            throw std::invalid_argument(
                "attachment to render target failed, due to resolution mismatch (" +
                ResToStr(resolution) + " given, but expected " + ResToStr(resolution_) + ")"
            );
        }
    }
    else
        resolution_ = resolution;
}

void RenderTarget::ApplyMipResolution(Texture& texture, unsigned int mipLevel)
{
    /* Apply texture size to render target resolution */
    auto size = texture.QueryMipLevelSize(mipLevel);
    ApplyResolution({ size.x, size.y });
}

void RenderTarget::ResetResolution()
{
    resolution_ = Gs::Vector2ui(0, 0);
}


} // /namespace LLGL



// ================================================================================
