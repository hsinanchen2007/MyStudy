### 解题思路
把员工和他们对应的经理对应起来,即员工的ManagerId = 经理的Id关联起来,然后对比大小就可以了

### 代码

```mysql
# Write your MySQL query statement
select e1.Name as Employee from Employee e1 left join Employee e2 on e1.ManagerId = e2.Id where e1.Salary > e2.Salary;
```