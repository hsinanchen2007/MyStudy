#### 方法：使用 `avg()` 和 `case...when...` [Accepted]

**想法**

通过如下 3 步解决这个问题。

**算法**

1. 计算公司每个月的平均工资
MySQL 有一个内置函数 avg() 获得一列数字的平均值。同时我们需要将 *pay_date* 列按一定格式输出以便后面使用。

```sql []
select avg(amount) as company_avg,  date_format(pay_date, '%Y-%m') as pay_month
from salary
group by date_format(pay_date, '%Y-%m')
;
```

| company_avg | pay_month |
|-------------|-----------|
| 7000.0000   | 2017-02   |
| 8333.3333   | 2017-03   |

2. 计算每个部门每个月的平均工资
为了实现这个目标，我们将 **salary** 表和 **employee** 表用条件 `salary.employee_id = employee.id` 连接起来。

```sql []
select department_id, avg(amount) as department_avg, date_format(pay_date, '%Y-%m') as pay_month
from salary
join employee on salary.employee_id = employee.employee_id
group by department_id, pay_month
;
```

| department_id | department_avg | pay_month |
|---------------|----------------|-----------|
| 1             | 7000.0000      | 2017-02   |
| 1             | 9000.0000      | 2017-03   |
| 2             | 7000.0000      | 2017-02   |
| 2             | 8000.0000      | 2017-03   |

3. 将 2 中的表和之前的公司数据作比较并求出结果
如果没用过 MySQL 的流控制语句 [`case...when...`](https://dev.mysql.com/doc/refman/5.7/en/case.html) 那这一步会是最难的。

就像其他语言一样，MySQL 也有流控制语句，点击 [这里](https://dev.mysql.com/doc/refman/5.7/en/flow-control-statements.html) 了解更多。

最后，将上面两个查询结合起来并用 `on department_salary.pay_month = company_salary.pay_month` 将它们连接。

```sql []
select department_salary.pay_month, department_id,
case
  when department_avg>company_avg then 'higher'
  when department_avg<company_avg then 'lower'
  else 'same'
end as comparison
from
(
  select department_id, avg(amount) as department_avg, date_format(pay_date, '%Y-%m') as pay_month
  from salary join employee on salary.employee_id = employee.employee_id
  group by department_id, pay_month
) as department_salary
join
(
  select avg(amount) as company_avg,  date_format(pay_date, '%Y-%m') as pay_month from salary group by date_format(pay_date, '%Y-%m')
) as company_salary
on department_salary.pay_month = company_salary.pay_month
;
```
