### 解题思路
因为不能用排序窗口函数，就选择用变量+if函数来解答，代码略微长了点，还能再精简的。
题目要求取出各部门工资前三的信息，看到8500有两位，那么就是从有重复记录排名值的表里筛选的，步骤如下：
1.首先两张表内连接组成新表t3
2.三个变量：@rank记录排名初始值为0，@a记录部门ID，@b记录工资，@a和@b初始值均为空，搭配if函数，逻辑如下：
第一条数据：@a=null<>Id，于是@rank取值1，@a取当前Id，@b取当前Salary
第二条数据：@a=上一条Id=当前Id，于是@rank根据@b判断：@b=上一条Salary<>当前Salary，那么执行@rank+1
……
当执行第N条数据如遇到@b=上一条Salary=当天Salary，那么@rank取回上一条记录，产生重复值
3.最后，从排名表里面依据条件选出字段Deparment,Employee,Salary

### 代码

```mysql
select Department
    ,Employee
    ,Salary
from (
select Department
    ,Employee
    ,Salary
    ,@rank:=if(@a=Id,if(@b=Salary,@rank,@rank+1),1) as rank
    ,@a:=Id
    ,@b:=Salary
from (
select t2.Id
    ,t2.Name as Department
    ,t1.Name as Employee
    ,t1.Salary
from Employee t1 
join Department t2 on t1.DepartmentId=t2.Id
order by t1.DepartmentId,t1.Salary desc ) t3
join (select @rank:=0,@a:=null,@b:=null) t4 ) t
where rank <=3;


```