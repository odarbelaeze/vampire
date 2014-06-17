#ifndef SPINTORQUE_INTERNAL_H_
#define SPINTORQUE_INTERNAL_H_
//-----------------------------------------------------------------------------
//
// This header file is part of the VAMPIRE open source package under the
// GNU GPL (version 2) licence (see licence file for details).
//
// (c) R F L Evans 2014. All rights reserved.
//
//-----------------------------------------------------------------------------

//---------------------------------------------------------------------
// Defines shared internal data structures and functions for the
// spin-torque implementation. These functions should not be accessed
// outside of the spin-torque code.
//---------------------------------------------------------------------
namespace st{
   namespace internal{
      
      //-----------------------------------------------------------------------------
      // Shared variables used for the spin torque calculation
      //-----------------------------------------------------------------------------
      extern bool enabled; // enable spin torque calculation

      extern double micro_cell_size; /// lateral size of spin torque microcells
      extern double micro_cell_thickness; /// thickness of spin torque microcells (atomistic)
      
      extern int num_local_atoms; /// number of local atoms (ignores halo atoms in parallel simulation)
      extern int current_direction; /// direction for current x->0, y->1, z->2
      //   std::vector< std::vector< micro_cell_t > > stack;
      extern std::vector<int> atom_st_index; // mc which atom belongs to
      extern std::vector<double> x_field_array; // arrays to store atomic spin torque field
      extern std::vector<double> y_field_array;
      extern std::vector<double> z_field_array;

      extern int num_stacks;  // total number of stacks
      extern int num_x_stacks; // number of stacks in x
      extern int num_y_stacks; // number of stack in y
      extern int num_microcells_per_stack; // number of microcells per stack

      extern std::vector<int> stack_index; // start of stack in microcell arrays

      extern std::vector<double> beta_cond; /// spin polarisation (conductivity)
      extern std::vector<double> beta_diff; /// spin polarisation (diffusion)
      extern std::vector<double> sa_infinity; /// intrinsic spin accumulation
      extern std::vector<double> lambda_sdl; /// spin diffusion length

      // three-vector arrays
      extern std::vector<double> pos; /// stack position
      extern std::vector<double> m; // magnetisation
      extern std::vector<double> j; // spin current
      extern std::vector<double> sa; // spin accumulation
      extern std::vector<double> spin_torque; // spin torque
      extern std::vector<double> ast; // adiabatic spin torque
      extern std::vector<double> nast; // non-adiabatic spin torque
      
      // material parameters for spin torque calculation
      struct mp_t{
         double beta_cond; /// spin polarisation (conductivity)
         double beta_diff; /// spin polarisation (diffusion)
         double sa_infinity; /// intrinsic spin accumulation
         double lambda_sdl; /// spin diffusion length
      };

      // array of material properties
      extern std::vector<st::internal::mp_t> mp;

      // default material properties
      extern st::internal::mp_t default_properties;

      //-----------------------------------------------------------------------------
      // Shared functions used for the spin torque calculation
      //-----------------------------------------------------------------------------
      void output_microcell_data();
      void calculate_spin_accumulation();
      void update_cell_magnetisation(const std::vector<double>& x_spin_array,
                                     const std::vector<double>& y_spin_array,
                                     const std::vector<double>& z_spin_array,
                                     const std::vector<int>& atom_type_array,
                                     const std::vector<double>& mu_s_array);
      
   } // end of iternal namespace
} // end of st namespace

#endif //SPINTORQUE_INTERNAL_H_
