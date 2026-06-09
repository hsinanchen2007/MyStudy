### 解题思路
此题关键在于找出非禁止用户，然后计算取消率


### 代码

```mysql
select t.request_at `Day`, round(sum(if(t.status <> 'completed', 1, 0)) / count(t.request_at), 2) `Cancellation Rate`
from Trips t
join users u1 on u1.role = 'client' and u1.users_id = t.client_id and u1.banned = 'No' -- 关联用户
join users u2 on u2.role = 'driver' and u2.users_id = t.driver_id and u2.banned = 'No' -- 关联司机 
and t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at;
```