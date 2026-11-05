Assumptions

Floors are visited in the order given, with no reordering or optimization.
Travel time is distance × 10. There’s no time for doors, stops, acceleration or boarding.
The starting floor is included in the visited list, as in the spec’s example.
Negative floors are valid (basements).
Floors are integers, and there’s no maximum floor.
Repeating the current floor does not count as a visit and adds 0 time.
There’s a single elevator with unlimited capacity.

Not implemented

Request scheduling or optimization (e.g. the SCAN algorithm, which serves floors in the current direction first).
Door and stop timing.
Multiple elevators.
Capacity and weight limits.
Real-time requests arriving during travel.
Arguments in any order (floor= before start=).

Error handling

Requires two arguments start={starting floor} floors={floors}.

example 
input = ./elevator start=12 floor=2,9,1,32

output = 560 12,2,9,1,32