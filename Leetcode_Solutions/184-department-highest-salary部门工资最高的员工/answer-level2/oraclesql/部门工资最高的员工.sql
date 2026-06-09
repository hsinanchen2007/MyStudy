错误版本：
-- 一开始写错了，疑问在于不知道把name怎么加进去。
-- 但是直接把name加max后面会形成错位，name是按照原顺序来的
select c.Department,c.Employee,c.max_salary as Salary
from 

(select b.Name as Department,max(a.Salary) as max_salary
from Employee a
inner join Department b
on a.DepartmentId=b.Id
group by 1)c



正确版本一：

用两次join
select b.Name as Department,a.Name as Employee,a.Salary
from Employee a
inner join Department b
on a.DepartmentId=b.Id
inner join
(
    select DepartmentId,max(Salary) as max_salary
    from Employee
    group by 1) c
on c.max_salary=a.Salary and a.DepartmentId=c.DepartmentId


正确版本二：
用oracle的 dense_rank 一开始我是不太明白为什么不能用row_number。另外我想吐槽mysql用不了row_number
不过如果存在两条以上的话，的确要用dense_rank或者rank。如果是取并列第一，dense_rank 是1 1 2，rank是113，row_number 是123


select b.Name as Department,a.Employee as Employee,a.Salary as Salary
from
    (select Id,Name,Salary,DepartmentId,
    dense_rank() over(partition by DepartmentId order by Salary desc) as rank_ 
    from Employee) a
inner join Department b
on a.Id=b.Id
where a.rank_=1


正确版本三：
被官方的(a.DepartmentId,a.Salary)in  两个同时in 折服了！！！




select b.Name as Department,a.Name as Employee,a.Salary
from Employee a
inner join Department b
on a.DepartmentId=b.Id
where (a.DepartmentId,a.Salary)in
(
    select DepartmentId,max(Salary)
    from Employee
    group by 1) 
