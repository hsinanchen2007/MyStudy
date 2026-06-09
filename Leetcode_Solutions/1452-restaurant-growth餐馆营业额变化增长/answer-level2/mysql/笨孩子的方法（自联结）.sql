### 解题思路
自联结，要注意同一日期如果有多行会重复计算。同时尽量使用日期函数

### 代码

```mysql
# Write your MySQL query statement below
select  a.visited_on, round(sum(b.amount)/cf,0) as amount, round(sum(b.amount)/(7*cf),2) as average_amount
from Customer a,Customer b,
(select visited_on,count(1) as cf
from Customer
group by visited_on) c
where datediff(a.visited_on,b.visited_on)>=0 and datediff(a.visited_on,b.visited_on)<7  and c.visited_on=a.visited_on
group by a.visited_on
having DATE_ADD(a.visited_on,INTERVAL -6 DAY)in (select visited_on from Customer)

```