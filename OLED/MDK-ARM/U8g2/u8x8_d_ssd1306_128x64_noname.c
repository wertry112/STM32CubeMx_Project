#include "u8x8.h"

static const uint8_t u8x8_d_ssd1306_128x64_noname_init_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0ae),
  U8X8_CA(0x0d5, 0x080),
  U8X8_CA(0x0a8, 0x03f),
  U8X8_CA(0x0d3, 0x000),
  U8X8_C(0x040),
  U8X8_CA(0x08d, 0x014),
  U8X8_CA(0x020, 0x000),
  U8X8_C(0x0a1),
  U8X8_C(0x0c8),
  U8X8_CA(0x0da, 0x012),
  U8X8_CA(0x081, 0x0cf),
  U8X8_CA(0x0d9, 0x0f1),
  U8X8_CA(0x0db, 0x040),
  U8X8_C(0x02e),
  U8X8_C(0x0a4),
  U8X8_C(0x0a6),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_vcomh0_init_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0ae),
  U8X8_CA(0x0d5, 0x080),
  U8X8_CA(0x0a8, 0x03f),
  U8X8_CA(0x0d3, 0x000),
  U8X8_C(0x040),
  U8X8_CA(0x08d, 0x014),
  U8X8_CA(0x020, 0x000),
  U8X8_C(0x0a1),
  U8X8_C(0x0c8),
  U8X8_CA(0x0da, 0x012),
  U8X8_CA(0x081, 0x0ef),
  U8X8_CA(0x0d9, 0x0a1),
  U8X8_CA(0x0db, 0x000),
  U8X8_C(0x02e),
  U8X8_C(0x0a4),
  U8X8_C(0x0a6),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_alt0_init_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0ae),
  U8X8_CA(0x0d5, 0x080),
  U8X8_CA(0x0a8, 0x03f),
  U8X8_CA(0x0d3, 0x000),
  U8X8_C(0x040),
  U8X8_CA(0x08d, 0x014),
  U8X8_CA(0x020, 0x000),
  U8X8_C(0x0a1),
  U8X8_C(0x0c8),
  U8X8_CA(0x0da, 0x002),
  U8X8_CA(0x081, 0x0cf),
  U8X8_CA(0x0d9, 0x0f1),
  U8X8_CA(0x0db, 0x040),
  U8X8_C(0x02e),
  U8X8_C(0x0a4),
  U8X8_C(0x0a6),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_sh1106_128x64_winstar_init_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0xae),
  U8X8_C(0xa4),
  U8X8_CA(0xd5, 0x50),
  U8X8_CA(0xa8, 0x3f),
  U8X8_CA(0xd3, 0x00),
  U8X8_C(0x40),
  U8X8_CA(0xad, 0x8b),
  U8X8_CA(0xd9, 0x22),
  U8X8_CA(0xdb, 0x35),
  U8X8_C(0x32),
  U8X8_CA(0x81, 0xff),
  U8X8_C(0x0a6),
  U8X8_CA(0x0da, 0x012),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1312_128x64_noname_init_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0ae),
  U8X8_CA(0x0d5, 0x080),
  U8X8_CA(0x0a8, 0x03f),
  U8X8_CA(0x0d3, 0x000),
  U8X8_C(0x040),
  U8X8_CA(0x08d, 0x014),
  U8X8_CA(0x020, 0x000),
  U8X8_C(0x0a1),
  U8X8_C(0x0c0),
  U8X8_CA(0x0da, 0x012),
  U8X8_CA(0x081, 0x0cf),
  U8X8_CA(0x0d9, 0x0f1),
  U8X8_CA(0x0db, 0x040),
  U8X8_C(0x02e),
  U8X8_C(0x0a4),
  U8X8_C(0x0a6),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_noname_powersave0_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0af),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_noname_powersave1_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0ae),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_noname_flip0_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0a1),
  U8X8_C(0x0c8),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1306_128x64_noname_flip1_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0a0),
  U8X8_C(0x0c0),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1312_128x64_noname_flip0_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0a1),
  U8X8_C(0x0c0),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static const uint8_t u8x8_d_ssd1312_128x64_noname_flip1_seq[] = {
  U8X8_START_TRANSFER(),
  U8X8_C(0x0a0),
  U8X8_C(0x0c8),
  U8X8_END_TRANSFER(),
  U8X8_END()
};

static uint8_t u8x8_d_ssd1306_sh1106_generic(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  uint8_t x, c;
  uint8_t *ptr;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_SET_POWER_SAVE:
      if ( arg_int == 0 )
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_powersave0_seq);
      else
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_powersave1_seq);
      break;
    case U8X8_MSG_DISPLAY_SET_FLIP_MODE:
      if ( arg_int == 0 )
      {
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_flip0_seq);
        u8x8->x_offset = u8x8->display_info->default_x_offset;
      }
      else
      {
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_flip1_seq);
        u8x8->x_offset = u8x8->display_info->flipmode_x_offset;
      }
      break;
#ifdef U8X8_WITH_SET_CONTRAST
    case U8X8_MSG_DISPLAY_SET_CONTRAST:
      u8x8_cad_StartTransfer(u8x8);
      u8x8_cad_SendCmd(u8x8, 0x081 );
      u8x8_cad_SendArg(u8x8, arg_int );
      u8x8_cad_EndTransfer(u8x8);
      break;
#endif
    case U8X8_MSG_DISPLAY_DRAW_TILE:
      u8x8_cad_StartTransfer(u8x8);
      x = ((u8x8_tile_t *)arg_ptr)->x_pos;
      x *= 8;
      x += u8x8->x_offset;
      u8x8_cad_SendCmd(u8x8, 0x040 );
      u8x8_cad_SendCmd(u8x8, 0x010 | (x>>4) );
      u8x8_cad_SendArg(u8x8, 0x000 | ((x&15)));
      u8x8_cad_SendArg(u8x8, 0x0b0 | (((u8x8_tile_t *)arg_ptr)->y_pos));
      do
      {
        c = ((u8x8_tile_t *)arg_ptr)->cnt;
        ptr = ((u8x8_tile_t *)arg_ptr)->tile_ptr;
        u8x8_cad_SendData(u8x8, c*8, ptr);
        arg_int--;
      } while( arg_int > 0 );
      u8x8_cad_EndTransfer(u8x8);
      break;
    default:
      return 0;
  }
  return 1;
}

static const u8x8_display_info_t u8x8_ssd1306_128x64_noname_display_info =
{
  0,
  1,
  20,
  10,
  100,
  100,
  50,
  50,
  8000000UL,
  0,
  4,
  40,
  150,
  16,
  8,
  0,
  0,
  128,
  64
};

uint8_t u8x8_d_ssd1306_128x64_noname(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_ssd1306_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}

uint8_t u8x8_d_ssd1312_128x64_noname(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_SET_FLIP_MODE:
      if ( arg_int == 0 )
      {
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1312_128x64_noname_flip0_seq);
        u8x8->x_offset = u8x8->display_info->default_x_offset;
      }
      else
      {
        u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1312_128x64_noname_flip1_seq);
        u8x8->x_offset = u8x8->display_info->flipmode_x_offset;
      }
      break;
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1312_128x64_noname_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_ssd1306_128x64_noname_display_info);
      break;
    default:
      if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
        return 1;
  }
  return 1;
}

uint8_t u8x8_d_ssd1306_128x64_vcomh0(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_vcomh0_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_ssd1306_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}

uint8_t u8x8_d_ssd1306_128x64_alt0(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_alt0_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_ssd1306_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}

static const u8x8_display_info_t u8x8_sh1106_128x64_noname_display_info =
{
  0,
  1,
  20,
  10,
  100,
  100,
  50,
  50,
  4000000UL,
  0,
  4,
  40,
  150,
  16,
  8,
  2,
  2,
  128,
  64
};

uint8_t u8x8_d_sh1106_128x64_noname(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_noname_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_sh1106_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}

uint8_t u8x8_d_sh1106_128x64_vcomh0(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_ssd1306_128x64_vcomh0_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_sh1106_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}

uint8_t u8x8_d_sh1106_128x64_winstar(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  if ( u8x8_d_ssd1306_sh1106_generic(u8x8, msg, arg_int, arg_ptr) != 0 )
    return 1;
  switch(msg)
  {
    case U8X8_MSG_DISPLAY_INIT:
      u8x8_d_helper_display_init(u8x8);
      u8x8_cad_SendSequence(u8x8, u8x8_d_sh1106_128x64_winstar_init_seq);
      break;
    case U8X8_MSG_DISPLAY_SETUP_MEMORY:
      u8x8_d_helper_display_setup_memory(u8x8, &u8x8_sh1106_128x64_noname_display_info);
      break;
    default:
      return 0;
  }
  return 1;
}
