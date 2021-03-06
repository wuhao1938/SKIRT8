/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#ifndef TRUSTSILICATEGRAINCOMPOSITION_HPP
#define TRUSTSILICATEGRAINCOMPOSITION_HPP

#include "GrainComposition.hpp"

////////////////////////////////////////////////////////////////////

/** The TrustSilicateGrainComposition class represents the optical and calorimetric properties of
    silicate dust grains according to the dust model used for the TRUST benchmark simulations. The
    underlying data is provided by Karel Misselt as part of a download from the TRUST web site
    (http://ipag.osug.fr/RT13/RTTRUST/opa.php) describing the BARE-GR-S model of Zubko, Dwek, and
    Arendt 2004, ApJS, 152, 211. */
class TrustSilicateGrainComposition : public GrainComposition
{
    ITEM_CONCRETE(TrustSilicateGrainComposition, GrainComposition, "a TRUST silicate dust grains composition")
    ITEM_END()

    //============= Construction - Setup - Destruction =============

public:
    /** This constructor can be invoked by dust mix classes that wish to hard-code the creation of
        a new grain composition object of this type (as opposed to creation through the ski file).
        Before the constructor returns, the newly created object is hooked up as a child to the
        specified parent in the simulation hierarchy (so it will automatically be deleted), and
        it's setup() function has been called. */
    explicit TrustSilicateGrainComposition(SimulationItem* parent);

protected:
    /** This function reads the raw optical and calorimetric data from resource files, and sets the
        bulk mass density to the value of 3500 kg/m\f$^3\f$ for silicate grains. */
    void setupSelfBefore() override;

    //====================== Identifying =====================

public:
    /** This function returns a brief human-readable identifier for the type of grain composition
        represented by the instance. */
    string name() const override;
};

////////////////////////////////////////////////////////////////////

#endif
