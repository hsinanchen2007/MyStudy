```
select
	d2.Name as Department,
	t1.Name as Employee,
	t1.Salary as Salary
from
	(select
	e1.DepartmentId,
	e1.Salary,
	e1.Name,
	(case  when @dep= e1.DepartmentId and e1.Salary=@sal then @t:=@t
	 when @dep=e1.DepartmentId and e1.Salary!=@sal then @t:=@t+1 
		else @t:=1 end) as tmp_tk,
	@dep:=e1.DepartmentId as tmp_dep,
    @sal:=e1.Salary
from
	(select @t:=0,@dep:=-1,@sal:=-1) t ,Employee e1
order by e1.DepartmentId,e1.Salary desc
) t1 join Department d2 on t1.DepartmentId=d2.Id and t1.tmp_tk<=3
```
