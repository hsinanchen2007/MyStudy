### 解题思路
此处撰写解题思路
第一步：连接两个表，根据部门和薪资排序；
第二步：利用变量根据薪资排序
第三步，选出排名小于等于3的所有记录



### 代码

select t3.Department,
        t3.Employee,
        t3.Salary
from
    (select 
        t1.Department,
        t1.name Employee,
        t1.Salary,
        case when @dep =Department and @sal =Salary then  @rk:= @rk
            when @dep =Department and @sal!=Salary then  @rk:=@rk+1 
            else @rk :=1  end rank ,
        @dep:=Department  ,
        @sal:=Salary   
    from 
        (select e.* ,d.name Department
        from Employee e
        join Department d 
        on e.departmentID = d.id 
        order by departmentID, Salary DESC ) t1,
        (select @rk:=0, @sal:='', @dep:='') t2) t3 
where rank <=3;        
```