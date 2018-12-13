#include "vm.h"

void v_jo(v_register *v_reg)
{
  DEBUG("jo\n");

  v_info *info = parse(v_reg, 1);

  if (v_reg->v_eflags & 0x800) {
    if (info[0].SIGN == 2) {
      v_reg->v_rip -= *(long long *)info[0].operand;
    }
    else {
      v_reg->v_rip += *(long long *)info[0].operand;
    }
  }

  free(info);
}
