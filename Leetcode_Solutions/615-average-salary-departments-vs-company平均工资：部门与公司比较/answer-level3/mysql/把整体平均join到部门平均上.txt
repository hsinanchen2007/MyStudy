### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
-- select date_format(pay_date, "%Y-%m") as pay_month, avg(amount)
-- from salary
-- group by 1

select lhs.pay_month, department_id,
    case when avg_dep > avg_total then 'higher'
         when avg_dep = avg_total then 'same'
         when avg_dep < avg_total then 'lower' end
         as comparison 
from
(select e1.department_id, date_format(s1.pay_date, "%Y-%m") as pay_month, avg(amount) as avg_dep
from
salary as s1
join
employee as e1
on s1.employee_id = e1.employee_id
group by 1,2) as lhs
join
(select date_format(pay_date, "%Y-%m") as pay_month, avg(amount) as avg_total
from salary
group by 1) as rhs
on lhs.pay_month = rhs.pay_month
```