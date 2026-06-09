代码和思路如下：

```
# Write your MySQL query statement below

# 先对非禁止用户(2013-10-01~2013-10-03)生成的订单总数进行筛选；
# 利用标志位tag对某个状态的订单进行标记，便于统计;
# 求被标记的订单总数/筛选订单，并按日期分组;

select t1.Request_at as Day, round(sum(t1.tag)/count(t1.Id),2) as "Cancellation Rate" from
(select t.Id, t.Status, t.Request_at, if(t.Status='completed',0,1) as tag
from Trips t where t.Client_Id IN 
(select Users_Id from Users u where u.Banned='No') and Driver_Id IN
(select Users_Id from Users u where u.Banned='No') and t.Request_at between '2013-10-01' and '2013-10-03') t1 group by t1.Request_at;
```
