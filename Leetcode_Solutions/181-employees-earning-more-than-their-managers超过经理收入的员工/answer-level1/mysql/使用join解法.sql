### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select  e1.name as Employee 
from Employee e1 join Employee e2 on e2.id = e1.ManagerId 
where e1.Salary > e2.Salary
```

重点：将员工所属的id和经理相同的表连接起来，（就是同一张表看作两张表，使用join，因为同行才能进行比较）
