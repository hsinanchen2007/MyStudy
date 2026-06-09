select distinct C1.seat_id
from cinema C1,cinema C2
where C1.free=1 and C2.free=1 and (C1.seat_id+1=C2.seat_id or C1.seat_id-1=C2.seat_id)