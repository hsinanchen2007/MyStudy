### 解题思路
后台审核在开玩笑，拿一个1,100 2,100 的数据来测试 第一的金额。。。

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary
      from (
      select a.Salary,
        (select count(distinct b.Salary)  from  Employee b  where b.Salary >= a.Salary) as n
      from Employee a
    ) w 
    where w.n = N
  );
END
```