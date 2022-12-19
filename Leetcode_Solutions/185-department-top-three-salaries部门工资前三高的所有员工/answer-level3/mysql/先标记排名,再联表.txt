### 解题思路
1.先排名
使用局部变量,以部门分组,按照Salary的值倒序排名
select tmp.Salary,tmp.DepartmentId,cast(if(@dId=tmp.DepartmentId,@rank:=@rank+1,@rank:=1)as signed) rank,                  @dId:=tmp.DepartmentId dptId from 
        (select distinct Salary,DepartmentId from Employee order by DepartmentId asc, Salary desc) tmp ,                          (select @rank:=1,@dId:=null) rank
2.得到排名后联表关联Employee和Department表,取需要的字段即可


### 代码

```mysql
# Write your MySQL query statement below

select d.Name Department,e.Name Employee,e.Salary from Employee e join Department d on e.DepartmentId = d.Id join
    (select tmp.Salary,tmp.DepartmentId,cast(if(@dId=tmp.DepartmentId,@rank:=@rank+1,@rank:=1)as signed) rank,                  @dId:=tmp.DepartmentId dptId from 
        (select distinct Salary,DepartmentId from Employee order by DepartmentId asc, Salary desc) tmp ,                          (select @rank:=1,@dId:=null) rank) rankTable 
  on rankTable.DepartmentId = d.Id and rankTable.Salary = e.Salary where rankTable.rank < 4 order by d.Id asc,e.Salary desc,e.Id asc;
```