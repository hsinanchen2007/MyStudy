### 解题思路
这里代码和MYSQL 通用。但是需要注意，MSSQL 两个整数做除法，如果想要得到小数，必须将分子转化为小数。所以在这道题，如果不转化分子，MYSQL中可以得到正确答案，但是SQL server 会返回 0.

### 代码

```mssql
/* Write your T-SQL query statement below */

select t.Request_at as Day,
	round (cast(sum(case when t.Status = 'completed' then 0 else 1 end) as float)/count(t.Status),2) as 'Cancellation Rate' 
from Trips t
	left join Users u on t.Client_ID = u.Users_Id
	left join Users u2 on t.Driver_ID = u2.Users_Id
where Request_at between '2013-10-01' and '2013-10-03' 
	and u.Banned = 'No'
	and u2.Banned = 'No'
group by t.Request_at
```