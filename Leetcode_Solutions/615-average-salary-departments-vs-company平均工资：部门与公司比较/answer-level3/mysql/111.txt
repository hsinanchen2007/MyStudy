### 解题思路
此处撰写解题思路
#1.根据时间和部门求出每个部门每个月份的工资 2.求出公司每个月的平均工资
### 代码

```mysql
# Write your MySQL query statement below
select b1.d1 as pay_month,b1.department_id,(case when b1.a1>b2.a2 then 'higher' when b1.a1<b2.a2 then 'lower' else 'same' end) as comparison
from
(select department_id,date_format(pay_date,'%Y-%m') as d1,avg(amount) as a1
from salary s inner join employee e
on s.employee_id =e.employee_id
group by department_id,date_format(pay_date,'%Y-%m')) b1
inner join
(select date_format(pay_date,'%Y-%m') as d2,avg(amount) as a2
from salary s inner join employee e
on s.employee_id =e.employee_id
group by date_format(pay_date,'%Y-%m')) b2
on b1.d1=b2.d2
order by b1.d1 desc,b1.department_id asc;

```