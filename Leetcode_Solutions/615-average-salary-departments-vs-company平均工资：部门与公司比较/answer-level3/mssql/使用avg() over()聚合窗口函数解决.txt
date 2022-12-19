思路：

使用avg() over()聚合窗口函数来解决。

将salary表和employee表通过员工id关联起来，分别计算每个月每个部门的平均工资avg_dept_salary，以及每个月公司所有员工的平均工资avg_com_salary。 但是这样会得到相同月份相同部门的重复的统计结果，因为一个部门有多个员工。因此最后的结果需要去重。

最后比较avg_dept_salary和avg_com_salary的大小就可以了。
```
select distinct convert(varchar(7),pay_date,120) as pay_month
    ,department_id
    ,case when avg_dept_salary > avg_com_salary then 'higher'
        when avg_dept_salary = avg_com_salary then 'same'
        else 'lower' end as comparison
from(
    select s.pay_date
        ,e.department_id
        ,avg(s.amount) over(partition by s.pay_date,e.department_id) as avg_dept_salary
        ,avg(s.amount) over(partition by s.pay_date) as avg_com_salary
    from salary s
    left join employee e on s.employee_id=e.employee_id
) t
```
执行用时 :810 ms, 内存消耗 :0B