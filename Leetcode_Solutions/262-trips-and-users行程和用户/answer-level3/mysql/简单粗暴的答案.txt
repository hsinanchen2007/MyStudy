### 解题思路
之前没注意到时间范围，后面加了个between and
就是把表全部连接起来，然后按照题目要求，筛选掉被禁止的用户（注意：乘客和司机是分开连接的，存在数据为空的情况，所以where后面选择的是!='Yes'，而不是='No'）
然后根据日期分组，按照题目求出取消率（这里使用了case when ）
后面把取消率重新命名的时候因为中间有空格，所以要用单引号引起来

### 代码

```mysql
# Write your MySQL query statement below
select a.request_at as day,
    round(sum(case when a.status != 'completed' then 1 else 0 end)/count(a.id),2) as 'cancellation rate'
from trips a
left join users b
on a.client_id =b.users_id
left join users c 
on a.driver_id = c.users_id 
where a.request_at between '2013-10-01' and '2013-10-03'
and b.banned != 'Yes'
and c.banned != 'Yes'
group by a.request_at
```