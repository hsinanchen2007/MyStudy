没有在实际应用中使用过这种查找奇数id的方法。但是确实蛮好用的。

select
c.*
from

cinema c

where c.description != 'boring' and id&1

order by c.rating desc