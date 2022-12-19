### 解题思路
做完后看了一下题解, 虽然有类似的了, 但是这是学习了定义用户变量后自己动手解决的第一个题目,以此为忆。
1. 首先对员工表进行部门,工资降序排序.但是如何每个部门只取三个呢?
2. 设置两个用户变量,一个计数一个用于验证部门ID
3. 当计数小于3或部门ID变更(由于是有序的)就符合条件, 记得去重
4. 再在字段表中对计数做判断赋值,若部门未变更则自增,否则重置为 1
5. 这样就将每个部门的前三的工资取出来了
6. 接下来就是一个多表联查了
### 代码

```mysql
# Write your MySQL query statement below



select d.Name as Department,e.Name as Employee,e.Salary
from Employee as e 
inner join Department as d 
on e.DepartmentId = d.Id 
inner join (
    select DepartmentId,Salary,@n := if(DepartmentId = @pre,@n+1,1),@pre := DepartmentId
    from
    (
        select distinct DepartmentId,Salary
        from Employee 
        order by DepartmentId,Salary desc
    ) as t1,(select @n := 1,@pre := null) as t2
    where @n < 3 or DepartmentId <> @pre
) as t 
on e.DepartmentId = t.DepartmentId and e.Salary = t.Salary
order by Department,Salary desc;
```