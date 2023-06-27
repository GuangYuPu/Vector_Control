#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float ccRA;
    float ccRB;
    float ccRC;
}Svpwm_t;

void Svpwm_Calculate(Svpwm_t *Svpwm,float Ud,float Ua_ref,float Ub_ref,float Uc_ref);

#ifdef __cplusplus
}
#endif
