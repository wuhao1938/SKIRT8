/*//////////////////////////////////////////////////////////////////
////     The SKIRT project -- advanced radiative transfer       ////
////       © Astronomical Observatory, Ghent University         ////
///////////////////////////////////////////////////////////////// */

#include "ProcessCommunicator.hpp"
#include "ProcessManager.hpp"

////////////////////////////////////////////////////////////////////

ProcessCommunicator::ProcessCommunicator()
{
}

////////////////////////////////////////////////////////////////////

ProcessCommunicator::~ProcessCommunicator()
{
    if (_rank != -1) ProcessManager::releaseMPI();
}

////////////////////////////////////////////////////////////////////

void ProcessCommunicator::setupSelfBefore()
{
    ProcessManager::acquireMPI(_rank,_Nprocs);
}

////////////////////////////////////////////////////////////////////

int ProcessCommunicator::rank() const
{
    return _rank;
}

////////////////////////////////////////////////////////////////////

int ProcessCommunicator::size() const
{
    return _Nprocs;
}

////////////////////////////////////////////////////////////////////

bool ProcessCommunicator::isMultiProc() const
{
    return (_Nprocs > 1);
}

////////////////////////////////////////////////////////////////////
