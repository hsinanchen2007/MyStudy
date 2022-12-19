### 解题思路
首先看到这个题目的时候，第一印象感觉有点难度的。因为以前工作中遇见一个差不多的例子：在表中查找分组中的极值问题。而表的数据一般在百万条左右，但写了各种sql都不能很好的解决，主要就是耗时太久。所以遇上这类问题，我基本都是都是很头痛的。
不过对于数量比较少的数据表而言，可以使用子查询来实现，不过这个方法以前用过，所以这次打算换一个思路。
1、首先需要将薪资表根据部门和薪资去重后做排序，
```mysql
select distinct t.Salary, t.DepartmentId from Employee t
```
2、将每一个部门的薪资添加做1、2、3...排序序号
```mysql
select @rowid := case when @deptid = a.DepartmentId then @rowid + 1 else 1 end as rowid, 
@deptid := case when @deptid = a.DepartmentId then @deptid else a.DepartmentId end as deptid, 
a.DepartmentId, a.Salary  
from 
(select distinct t.Salary, t.DepartmentId from Employee t ) a, (select @rowid := 0, @deptid := 0 ) t 
order by a.DepartmentId, a.Salary desc
```
3、获取前三的薪资信息
```mysql
select t0.Name Department, t1.Name Employee, t1.Salary 
from Department t0
inner join Employee t1 on t0.Id = t1.DepartmentId
inner join (select @rowid := case when @deptid = a.DepartmentId then @rowid + 1 else 1 end as rowid, 
@deptid := case when @deptid = a.DepartmentId then @deptid else a.DepartmentId end as deptid, 
a.DepartmentId, a.Salary  
from 
(select distinct t.Salary, t.DepartmentId from Employee t ) a, (select @rowid := 0, @deptid := 0 ) t 
order by a.DepartmentId, a.Salary desc) t2 on t1.DepartmentId = t2.DepartmentId and t1.Salary = t2.Salary and t2.rowid <= 3
order by t0.Id, t1.Salary desc
```