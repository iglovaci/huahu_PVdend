#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _Conductance_220811_reg(void);
extern void _gap_reg(void);
extern void _nethhwbm_reg(void);
extern void _netstimm_reg(void);
extern void _NMDA_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"Conductance_220811.mod\"");
    fprintf(stderr, " \"gap.mod\"");
    fprintf(stderr, " \"nethhwbm.mod\"");
    fprintf(stderr, " \"netstimm.mod\"");
    fprintf(stderr, " \"NMDA.mod\"");
    fprintf(stderr, "\n");
  }
  _Conductance_220811_reg();
  _gap_reg();
  _nethhwbm_reg();
  _netstimm_reg();
  _NMDA_reg();
}

#if defined(__cplusplus)
}
#endif
