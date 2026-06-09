### 解题思路
window function
两个lag
### 代码

```mssql
/* Write your T-SQL query statement below */

select distinct num as ConsecutiveNums
from
(select id,num, lag(num,1) over (order by id) as lag1,lag(num,2) over (order by id) as lag2
from logs) t
where num = lag1 and num = lag2





```