用join：执行用时 :363 ms, 在所有 MySQL 提交中击败了83.73%的用户...
不造这样在数据量大的情况下靠不靠谱...

select distinct P1.Email
from Person P1 join Person P2
on P1.Email = P2.Email
and P1.Id != P2.Id

