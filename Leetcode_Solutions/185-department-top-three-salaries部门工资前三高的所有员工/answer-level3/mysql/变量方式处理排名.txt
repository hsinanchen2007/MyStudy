### 解题思路
使用变量的方式，总的思路是保证每个departmentid 的排名是独立的。
在递增的时候使用departmentid，salary  desc 来排序。
- 1.在departmentid 不相等的就重置排名。
- 2.如果salary 与上一个一直，那排名就不变。否则递增。
- 3.最终在筛选排名前三的数据。

### 代码

```mysql
# Write your MySQL query statement below

SELECT d.Name as Department,a.name as Employee,a.Salary FROM (
    SELECT id,name,DepartmentId,Salary,@r:=if(@d=DepartmentId ,if(@s=Salary,@r,@r+1),0) as rr,@d:=DepartmentId,@s:=Salary   FROM Employee a ,(SELECT @r:=0 ,@d:=null,@s:=null) b order by DepartmentId,Salary desc
)as a 
inner join Department as d on a.DepartmentId=d.Id 
where a.rr <3
```