![image.png](https://pic.leetcode-cn.com/62958f924840a9d2b4e820ba1a1db99ec5564e501e5f8a5185d7b2b5020dbac0-image.png)

- **核心在于实现dense_number函数**


```
select d.Name as Department,employee.Name as Employee,Salary 
from 
(select Name,DepartmentId,Salary,
case when @dep= DepartmentId and @Salary=Salary then @dense
when @dep= DepartmentId and @Salary:=Salary then @dense:=@dense+1
when @dep:=DepartmentId then @dense:=1 end 
as dense
from  
(select @dense:= null,@dep:=null,@Salary:=null)a
,Employee e
order by DepartmentId asc,Salary desc
) employee  #实现dense_number函数
join 
Department d
on DepartmentId=Id
and dense<4
```
