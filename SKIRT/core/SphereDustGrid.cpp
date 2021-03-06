/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "SphereDustGrid.hpp"

//////////////////////////////////////////////////////////////////////

Box SphereDustGrid::boundingBox() const
{
    return Box(-_maxRadius,-_maxRadius,-_maxRadius, _maxRadius,_maxRadius,_maxRadius);
}

//////////////////////////////////////////////////////////////////////
