/* Tarang-4.0
 *
 * Copyright (C) 2008, 2009  Mahendra K. Verma
 *
 * Mahendra K. Verma
 * Indian Institute of Technology, Kanpur-208016
 * UP, India
 *
 * mkv@iitk.ac.in
 *
 * This file is part of Tarang-4.0 .
 *
 * Tarang-4.0 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * Tarang-4.0 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Tarang-4.0; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, U
 */

/*! \file  init_cond_field.cc
 * 
 * @brief   Read field vars from file field_in_file.
 *
 * @author  M. K. Verma
 * @version 4.0
 * @date Feb 2009
 */


#include "../IncFluid.h"


/**********************************************************************************************

						Input from a file: field_in_file	

***********************************************************************************************/


void  IncFluid::Init_cond()
{
	Input_prefix(field_in_file);
	

	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0;
	
	CV_input(field_in_file, *VF_temp);

	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	
	if (alias_switch == "DEALIAS")		Dealias();
	
}

//*********************************************************************************************
void  IncFluid::Init_cond(IncSF& T)
{   
	Input_prefix(field_in_file);
		
	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0; 
	(*T.F) = 0.0;
	
	CV_input(field_in_file, *VF_temp);
	T.CS_input(field_in_file, *VF_temp);

	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias(T);
}

//
//
//*********************************************************************************************
void  IncFluid::Init_cond(IncVF& W)
{ 
	Input_prefix(field_in_file);
   
	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0; 
	(*W.V1) = 0.0;  (*W.V2) = 0.0;  (*W.V3) = 0.0;
	
	CV_input(field_in_file, *VF_temp);
	W.CV_input(field_in_file, *VF_temp);
	
	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias(W);
}

//
//*********************************************************************************************
void  IncFluid::Init_cond(IncVF& W, IncSF& T)
{  
	Input_prefix(field_in_file);

	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0;
	(*W.V1) = 0.0;  (*W.V2) = 0.0;  (*W.V3) = 0.0; 
	(*T.F) = 0.0;
	
	CV_input(field_in_file, *VF_temp);
	W.CV_input(field_in_file, *VF_temp);
	T.CS_input(field_in_file, *VF_temp);
	
	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	
	if (alias_switch == "DEALIAS")		Dealias(W, T);
}


/**********************************************************************************************

						Input from a file: field_in_file(N_in_reduced[])

***********************************************************************************************/


// Fluid
void  IncFluid::Init_cond_reduced()
{   

	Input_prefix(field_in_file);

	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0;
	
	CV_input(field_in_file, N_in_reduced, *VF_temp);
	
	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias();
}

//*********************************************************************************************
// Passive scalar + RB convection

void  IncFluid::Init_cond_reduced(IncSF& T)
{    
	Input_prefix(field_in_file);
	
	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0; 
	(*T.F) = 0.0;
	
	CV_input(field_in_file, N_in_reduced, *VF_temp);
	T.CS_input(field_in_file, N_in_reduced, *VF_temp);

	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias(T);
}



//*********************************************************************************************
// MHD

void  IncFluid::Init_cond_reduced(IncVF& W)
{  
	Input_prefix(field_in_file);
	
	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0; 
	(*W.V1) = 0.0;  (*W.V2) = 0.0;  (*W.V3) = 0.0;
	
	CV_input(field_in_file, N_in_reduced, *VF_temp);
	W.CV_input(field_in_file, N_in_reduced, *VF_temp);

	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias(W);
}


//*********************************************************************************************
// Magnetoconvection

void  IncFluid::Init_cond_reduced(IncVF& W, IncSF& T)
{   
	Input_prefix(field_in_file);
	 
	(*V1) = 0.0;  (*V2) = 0.0;  (*V3) = 0.0;
	(*W.V1) = 0.0;  (*W.V2) = 0.0;  (*W.V3) = 0.0; 
	(*T.F) = 0.0;
	
	CV_input(field_in_file, N_in_reduced, *VF_temp);
	W.CV_input(field_in_file, N_in_reduced, *VF_temp);
	T.CS_input(field_in_file, N_in_reduced, *VF_temp);

	if (my_id == master_id) 
		cout  << "Reading of field configurations ended successfully" << endl; 
	
	if (alias_switch == "DEALIAS")		Dealias(W, T);
}


/**********************************************************************************************

						Input from a file: for RB convection

***********************************************************************************************/

void  IncFluid::Init_cond(string Pr_switch, IncSF& T)
{  

	if (Pr_switch == "PRZERO") 
	{
		Init_cond();	
					
		*T.F = *V1;  
		Array_divide_ksqr(basis_type, N, *T.F, kfactor);		
	}
	
	else
		Init_cond(T);
		
	Zero_modes_RB_slip(T);		
			
}


//*********************************************************************************************
void  IncFluid::Init_cond(string Pr_switch, IncVF& W, IncSF& T)
{  

	if (Pr_switch == "PRZERO") 
	{
		Init_cond(W);	
					
		*T.F = *V1;  
		Array_divide_ksqr(basis_type, N, *T.F, kfactor);	
	}
	
	else
		Init_cond(W, T);
		
	Zero_modes_RB_slip(W, T);	
	
}



//*********************************************************************************************
void  IncFluid::Init_cond_reduced(string Pr_switch, IncSF& T)
{   
 
	if (Pr_switch == "PRZERO") 
	{
		Init_cond_reduced();
						
		*T.F = *V1; 
		Array_divide_ksqr(basis_type, N, *T.F, kfactor);		
	}
	
	else
		Init_cond_reduced(T);

	Zero_modes_RB_slip(T);	
	
}


//*********************************************************************************************
void  IncFluid::Init_cond_reduced(string Pr_switch, IncVF& W, IncSF& T)
{  
 
	if (Pr_switch == "PRZERO") 
	{
		Init_cond_reduced(W);	
					
		*T.F = *V1; 
		Array_divide_ksqr(basis_type, N, *T.F, kfactor);		
	}
	
	else
		Init_cond_reduced(W, T);
		
	Zero_modes_RB_slip(W, T);	

}



//******************************** End of Init_cond_field.cc **********************************

  