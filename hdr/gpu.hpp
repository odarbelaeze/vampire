#ifndef GPU_H_
#define GPU_H_
//-----------------------------------------------------------------------------
//
// This header file is part of the VAMPIRE open source package under the
// GNU GPL (version 2) licence (see licence file for details).
//
// (c) R F L Evans 2015. All rights reserved.
//
//-----------------------------------------------------------------------------
#include <string>

namespace gpu{

   //-----------------------------------------------------------------------------
   // Variables used for GPU acceleration
   //-----------------------------------------------------------------------------
   extern bool acceleration; // flag to enable gpu_acceleration
   extern bool cpu_stats; // flag to calculate stats using cpu

   //-----------------------------------------------------------------------------
   // Functions for GPU acceleration
   //-----------------------------------------------------------------------------
   extern bool match_input_parameter(std::string const key, std::string const word, std::string const value, std::string const unit, int const line);
   extern void initialize();
   extern void llg_heun();
   extern void finalize();

   //-----------------------------------------------------------------------------
   // Functions for GPU ststistics calculation
   //-----------------------------------------------------------------------------
   namespace stats{

      extern void update();
      extern void reset();
      extern void get();

   }

} // end of gpu namespace

#endif //GPU_H_
