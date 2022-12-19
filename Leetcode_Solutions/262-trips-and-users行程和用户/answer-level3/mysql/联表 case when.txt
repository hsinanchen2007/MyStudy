### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
a.request_at as Day,
round(
count(case when b.banned='no' and a.status<>'completed' then 1 else null end)/
count(case when b.banned='no' then 1 else null end),2) as `Cancellation Rate`
 from trips a left join users b on a.client_id=b.users_id where a.request_at between '2013-10-01' and '2013-10-03' group by request_at
```