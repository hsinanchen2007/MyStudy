### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


SELECT d.Name Department,e.Name Employee,e.Salary 
FROM Employee e JOIN Department d 
WHERE  e.DepartmentId = d.Id AND 
(e.Salary,e.DepartmentId) IN (
    SELECT MAX(Salary),DepartmentId FROM Employee GROUP BY DepartmentId
)

最开始写了很多弯路。
最开始是考虑到已 Department 表为主表。每个 Department 都作为条件去表 Employee 中查询 部门下。金额最多的员工。
不过后来考虑到可能存在多个。

后来想想，直接将部门，与部门下最多的工资查询出来，作为一个中间表即可。作为过滤条件即可。
且 需要在 WHERE 条件 中 ，过滤掉没有部门的员工

```