### 解题思路
此处撰写解题思路
### 代码

```mysql
# Write your MySQL query statement below

select E2.name Employee from Employee E1 ,Employee E2 WHERE E1.Id=E2.ManagerId AND E1.salary<E2.salary
```