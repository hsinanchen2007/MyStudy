方法:使用自链接查询,并分组(去掉大量无用数据)
原理:
    通过条件a.Salary<b.Salary可知,比最高工资高的工资有0个,比第二高工资高的有1个,比第三高的有两个,以此类推。通过分组之后,再利用hvaing count(distinct b.id)来统计(不加distinct就不会把薪水一样的员工归为一个档次),如果要得出前三高的直接hvaing count(distinct b.id)<3便可,此方法有点难以理解!

代码:
    select 
        c.Name as Department,
        a.Name as Employee,
        a.Salary as Salary
    from Employee a left join Employee b on a.DepartmentId=b.DepartmentId
    and a.Salary<b.Salary
    join Department c on a.DepartmentId=c.Id
    group by a.Id,a.DepartmentId,a.Salary
    having count(distinct b.Salary)<3
    order by a.DepartmentId,a.Salary desc;
    