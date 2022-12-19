### 解题思路
首先是对两表需要提取的字段进行联合，这里使用inner join，并且使用dense_rank()划分部门并按部门人员工资排序返回序号，最后从中提取出rank值为1,2,3的即可

### 代码

```mssql
/* Write your T-SQL query statement below */
select Department,Employee,Salary from(
    select e.Name Employee,e.Salary Salary,d.Name Department,
    dense_rank() over(partition by e.DepartmentId order by e.Salary DESC) as rn
    from Employee e
    inner join Department d on e.DepartmentId = d.Id
)l1 where rn = 1 or rn =2 or rn=3
```