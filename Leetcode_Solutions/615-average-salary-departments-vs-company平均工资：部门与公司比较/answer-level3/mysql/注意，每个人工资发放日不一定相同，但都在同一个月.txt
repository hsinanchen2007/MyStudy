#思路：（1）按照部门，发放月分组;(2)组内查询套路：case when + select子查询
#
select date_format(s.pay_date,"%Y-%m") pay_month,e.department_id,
case when avg(s.amount)>(select avg(s1.amount) from salary s1 where date_format(s1.pay_date,"%Y-%m")=date_format(s.pay_date,"%Y-%m")) then "higher"
when avg(s.amount)=(select avg(s1.amount) from salary s1 where date_format(s1.pay_date,"%Y-%m")=date_format(s.pay_date,"%Y-%m")) then "same"
when avg(s.amount)<(select avg(s1.amount) from salary s1 where date_format(s1.pay_date,"%Y-%m")=date_format(s.pay_date,"%Y-%m")) then "lower" end comparison
from employee e left join salary s
on e.employee_id=s.employee_id
group by e.department_id,date_format(s.pay_date,"%Y-%m")