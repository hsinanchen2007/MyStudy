select ifnull(max(num),null) num
from (select num from my_numbers group by num having count(*)=1)M