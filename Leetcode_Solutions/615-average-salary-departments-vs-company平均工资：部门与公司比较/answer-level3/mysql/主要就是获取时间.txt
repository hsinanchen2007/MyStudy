### 解题思路
主要就是获取时间 然后用avg函数过滤就OK了
### 代码

```mysql
# Write your MySQL query statement below


 select s.pay_date as pay_month,e.department_id ,
case when round(avg(s.amount),4) > t.avg_money then 'higher'
else case when round(avg(s.amount),4) < t.avg_money then 'lower'
else 'same' end end `comparison`
 from 
 ( select left(pay_date,7) as pay_date,employee_id,amount from salary) s
  left join ( select avg(amount) as avg_money,left(pay_date,7) as pay_date from salary group by left(pay_date,7)) t on s.pay_date = t.pay_date left join employee e on s.employee_id = e.employee_id   
 group by s.pay_date,e.department_id order by e.department_id asc
 
 



```