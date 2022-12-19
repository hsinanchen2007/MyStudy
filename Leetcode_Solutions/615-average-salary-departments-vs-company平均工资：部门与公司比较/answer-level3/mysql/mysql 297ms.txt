### 解题思路
有点不相信为啥只击败了5.02% 待我看看其他人的写法

### 代码

```mysql
# Write your MySQL query statement below


select pay_month,department_id,
case when sal > csal then 'higher'
 when sal = csal then 'same'
 when sal < csal then 'lower'
end as comparison
from(
select date_format(pay_date,'%Y-%m') pay_month,department_id,
   avg(amount) sal
from salary a left join employee b on a.employee_id = b.employee_id
group by date_format(pay_date,'%Y%m'),department_id
) t ,(select date_format(pay_date,'%Y-%m') cmon,avg(amount) csal from salary
group by date_format(pay_date,'%Y-%m')) c
where t.pay_month = c.cmon
order by pay_month desc, department_id





```