#include "Coordinate_Trans.h"
#include "math.h"
#include "main.h"

void CT_Refresh_abc(CT_data_t *CTdata,float a,float b,float c,float theta)
{
    CTdata->AlphaBeta_value.alpha 
    = sqrt(2/3) * ((1)*CTdata->abc_value.a - (1/2)*CTdata->abc_value.b - (1/2)*CTdata->abc_value.c);
     CTdata->AlphaBeta_value.beta 
    = sqrt(2/3) * ((0)*CTdata->abc_value.a + (sqrt(3)/2)*CTdata->abc_value.b - (sqrt(3)/2)*CTdata->abc_value.c);

    CTdata->dq_value.d 
    = (2/3) * ((cos(theta))*CTdata->abc_value.a + (cos(theta-2*PI/3))*CTdata->abc_value.b + (cos(theta+2*PI/3))*CTdata->abc_value.c);
     CTdata->dq_value.q 
    = -(2/3) * ((sin(theta))*CTdata->abc_value.a + (sin(theta-2*PI/3))*CTdata->abc_value.b - (sin(theta+2*PI/3))*CTdata->abc_value.c);
}

void CT_Refresh_AlphaBeta(CT_data_t *CTdata,float alpha,float beta,float theta)
{
    CTdata->abc_value.a 
    = sqrt(2/3) * ((1)*CTdata->AlphaBeta_value.alpha - (0)*CTdata->AlphaBeta_value.beta);
    CTdata->abc_value.b
    = sqrt(2/3) * (-(1/2)*CTdata->AlphaBeta_value.alpha + (sqrt(3)/2)*CTdata->AlphaBeta_value.beta);
    CTdata->abc_value.c
    = sqrt(2/3) * (-(1/2)*CTdata->AlphaBeta_value.alpha - (sqrt(3)/2)*CTdata->AlphaBeta_value.beta);

    CTdata->dq_value.d 
    = (cos(theta))*CTdata->AlphaBeta_value.alpha + (sin(theta))*CTdata->AlphaBeta_value.beta;
     CTdata->dq_value.q 
    = -(sin(theta))*CTdata->AlphaBeta_value.alpha + (cos(theta))*CTdata->AlphaBeta_value.beta;
}

void CT_Refresh_dq(CT_data_t *CTdata,float d,float q,float theta)
{
    CTdata->abc_value.a 
    = cos(theta)*CTdata->dq_value.d - sin(theta)*CTdata->dq_value.q;
    CTdata->abc_value.b
    = cos(theta-2*PI/3)*CTdata->dq_value.d - sin(theta+2*PI/3)*CTdata->dq_value.q;
    CTdata->abc_value.c
   = cos(theta-2*PI/3)*CTdata->dq_value.d - sin(theta+2*PI/3)*CTdata->dq_value.q;

    CTdata->AlphaBeta_value.alpha 
    = (cos(theta))*CTdata->dq_value.d - (sin(theta))*CTdata->dq_value.q;
     CTdata->AlphaBeta_value.beta 
    = (sin(theta))*CTdata->dq_value.d + (cos(theta))*CTdata->dq_value.q;
}

void CT_get_AlphaBeta(CT_data_t *CTdata,float a,float b,float c)
{
    CTdata->AlphaBeta_value.alpha 
    = sqrt(2/3) * ((1)*CTdata->abc_value.a - (1/2)*CTdata->abc_value.b - (1/2)*CTdata->abc_value.c);
     CTdata->AlphaBeta_value.beta 
    = sqrt(2/3) * ((0)*CTdata->abc_value.a + (sqrt(3)/2)*CTdata->abc_value.b - (sqrt(3)/2)*CTdata->abc_value.c);
}

void CT_get_abc(CT_data_t *CTdata,float alpha,float beta)
{
    CTdata->abc_value.a 
    = sqrt(2/3) * ((1)*CTdata->AlphaBeta_value.alpha - (0)*CTdata->AlphaBeta_value.beta);
    CTdata->abc_value.b
    = sqrt(2/3) * (-(1/2)*CTdata->AlphaBeta_value.alpha + (sqrt(3)/2)*CTdata->AlphaBeta_value.beta);
    CTdata->abc_value.c
    = sqrt(2/3) * (-(1/2)*CTdata->AlphaBeta_value.alpha - (sqrt(3)/2)*CTdata->AlphaBeta_value.beta);
}