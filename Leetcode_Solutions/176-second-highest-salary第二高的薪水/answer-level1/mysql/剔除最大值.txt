### 解题思路
此处撰写解题思路
关键点：
1.找出最高的工资数，然后去和原表join，然后去掉这个最高工资的数据，看剩下的数据，按照工资高低排序取第一条
2.需要判断，因为不一定有数据，有数据的话，就显示工资，没有数据，则显示为null，所以要判断count(*)是否大于0
### 代码

```mysql
# Write your MySQL query statement below
select 
    if(count(Salary)>0,Salary,null) as SecondHighestSalary
from 
(
select 
    t1.Salary
from 
(
   select 
        Salary
    from 
        Employee 
    group by 
        Salary
) t1 
left join
(
    select 
        max(Salary) as Salary
    from 
        Employee
) t2 
on 
    t1.Salary = t2.Salary
where 
    t2.Salary is null
order by 
    t1.Salary desc 
limit 1
) t

```