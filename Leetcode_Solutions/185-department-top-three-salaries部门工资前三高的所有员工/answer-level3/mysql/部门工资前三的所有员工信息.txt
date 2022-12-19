### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select d.Name AS'Department',e1.Name AS'Employee', e1.Salary
from Employee e1
join Department d on e1. DepartmentId =d.Id
where 3>(
    select count(distinct E2.Salary)
        from Employee e2
        where e2.Salary >e1.Salary
        AND e1.DepartmentId=e2.DepartmentId);

```
思路：
第一：两表之间的id存在关系，多表查询连接
第二，要计算前三个，可以从count函数思考，使用子查询，获得N>count（DISTINCT 字段）的计数，同时这里面使用自连接，使得表中的工资进行比较，筛选出工资个数小于三个的

或者使用开窗函数 
SELECT *
FROM
(SELECT *,row_number() overpartition by 要分组的列名
                       order by 要排序的列名 desc)as 排名 
                    FROM 表名）as a
                where 排名 <=N