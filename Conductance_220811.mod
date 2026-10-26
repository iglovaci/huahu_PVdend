:A conductance
NEURON{
POINT_PROCESS shunt
NONSPECIFIC_CURRENT i 
RANGE i, e, g, del, dur
}

PARAMETER {
g =  0.01 (nS)
: units in the PARAMETER BLOCK is not taken into the calculation
e = 0 (millivolt)
del (ms)
dur (ms)
}


ASSIGNED {
i  (nanoamp)
v  (millivolt)
}

BREAKPOINT {
at_time(del)
at_time(del+dur)
if (t<del+dur && t >del) {i = g * (v-e)/1000}
    else {i=0}
}