#ifndef FLIPDOT_H_
#define FLIPDOT_H_

#include "platform_config.h"
#include <stddef.h>

#ifdef CFG_TYPE_FLIPDOT


void flipdot_init(void);

#ifdef CFG_TYPE_FLIPDOT_84X7
typedef struct
{
    uint8_t cols[84];
} fdisp_84x7_t;
extern fdisp_84x7_t flipdotState84x7;

void flipdot_wipe_84x7(const uint8_t dir);
void flipdot_set_84x7(const fdisp_84x7_t *d);
void flipdot_setstring_84x7(fdisp_84x7_t *d, uint8_t *s, size_t slen);
#endif // CFG_TYPE_FLIPDOT_84X7


#ifdef CFG_TYPE_FLIPDOT_112X16
typedef struct
{
    uint16_t cols[112];
} fdisp_112x16_t;
extern fdisp_112x16_t flipdotState112x16;

void flipdot_wipe_112x16(const uint8_t dir);
void flipdot_set_112x16(const fdisp_112x16_t *d);
void flipdot_setstring_112x16(fdisp_112x16_t *d, uint8_t *s, size_t slen);
#endif // CFG_TYPE_FLIPDOT_112X16

#endif // CFG_TYPE_FLIPDOT

#endif // FLIPDOT_H_