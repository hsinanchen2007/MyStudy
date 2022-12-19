### 解题思路
1.找出最大月份和最小月份
2.找出需要计算的月份，以及它们的求和范围
3.与原表连接，针对每一个ID和月份的需要计算的月份都列出来，然后根据ID和月份分类求和

### 代码

```mysql
# Write your MySQL query statement below
select s1.Id as Id, s1.Month as Month, sum(s2.Salary) as Salary
from(
    select t1.Id as Id, t1.Month as Month, t1.Salary as Salary, if(t2.startMonth+3<=t1.Month,t1.Month-2,t2.startMonth) as startMonth
    from Employee t1
    join(
        select Id, max(Month) as thisMonth, min(Month) as startMonth
        from Employee
        group by Id
    ) t2
    on t1.Id = t2.Id
    where t1.Month>=t2.startMonth and t1.Month<t2.thisMonth
) s1
join Employee s2
on s1.Id = s2.Id and s2.Month>=s1.startMonth and s2.Month<=s1.Month
group by s1.Id, s1.Month
order by s1.Id asc, s1.Month desc
```