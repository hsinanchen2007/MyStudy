### 解题思路
这里有个坑就是有人在同天多次登陆，恰好那天也是他第一次登陆的日子，要去重

### 代码

```mysql
# Write your MySQL query statement below

select  tr.activity_date as login_date , count(distinct t1.user_id) as user_count from Traffic as tr  #tr.activity_date as login_date , count(t1.fd) as
left join
(
select user_id , min(activity_date ) fd from 
Traffic as t 
where activity = 'login'
group by user_id 
) as t1
on tr.activity_date = t1.fd and t1.user_id = tr.user_id and tr.activity = 'login'
where datediff('2019-06-30',t1.fd) <=90
group by tr.activity_date
having user_count != 0


```