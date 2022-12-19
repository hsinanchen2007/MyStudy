### 解题思路
本题对于我而言的收获有二，
一是用join比where自己连接要容易很多
二是sum函数之中可以套用if语句，count则只是简单计数，我虽然不懂其中代码具体实现，但是我大概可以猜到sum是逐条语句进行判断的，所以可以再加if进行判断，同理加case也行

### 代码

```mysql
# Write your MySQL query statement below
select request_at as 'Day', round(sum(if(trips.status<>'completed', 1, 0))/count(trips.status), 2) as 'Cancellation Rate'
from trips
join users as u1 on (trips.client_id=u1.users_id and u1.banned='No')
join users as u2 on (trips.driver_id=u2.users_id and u2.banned='No')
where request_at between '2013-10-01' and '2013-10-03'
group by request_at;
```