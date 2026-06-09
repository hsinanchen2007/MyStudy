### 解题思路
有没有办法在dense_rank函数的时候去重啊 partition by Salary不能实现

### 代码

```oraclesql
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
   
    select Salary into result from (select Salary,dense_rank() over(order by Salary desc) as num from  (select distinct Salary from Employee)) where num=N;
    RETURN result;
END;
```