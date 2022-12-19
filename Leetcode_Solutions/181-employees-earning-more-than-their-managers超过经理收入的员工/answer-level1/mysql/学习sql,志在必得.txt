### 解题思路
创建两个表，我的思路是 第一清楚我们要的什么 再则就是去哪里去取 之后就是

### 代码

```mysql
# Write your MySQL query statement below
select a.Name as `Employee` from  Employee as a,Employee as b where b.Id = a.ManagerId and a.Salary > b.Salary;
```