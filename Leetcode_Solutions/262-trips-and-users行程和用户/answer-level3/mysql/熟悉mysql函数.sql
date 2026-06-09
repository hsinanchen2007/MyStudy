### 解题思路
熟悉mysql函数
round(1/3,2)保留2位小数，
count(if(?,true,false)) count函数里加判断
### 代码

```mysql



# Write your MySQL query statement below



select 
Trips.Request_at as Day,
round(count(if(Status != 'completed',Status, null))/count(*),2) as 'Cancellation Rate'
from 
Trips 
inner join Users u1 on Trips.Client_Id = u1.Users_Id and u1.Banned = 'No'
inner join Users u2 on Trips.Driver_Id = u2.Users_Id and u2.Banned = 'No'
where Request_at between '2013-10-01' and '2013-10-03'
group by Request_at


```