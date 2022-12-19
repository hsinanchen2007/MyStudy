
``` ORACLE
/* Write your PL/SQL query statement below */

--查询语句
select distinct(num) "ConsecutiveNums"
from (
	select num,(row_number() over(order by id )-row_number() over(partition by num order by id))                rank_
	from Logs
) tmp
group by rank_,num
having count(rank_)>=3;


```

