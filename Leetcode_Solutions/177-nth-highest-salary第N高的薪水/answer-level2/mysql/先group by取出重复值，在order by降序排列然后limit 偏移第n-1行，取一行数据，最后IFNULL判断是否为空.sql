### 解题思路
先group by取出重复值，在order by降序排列然后limit 偏移第n-1行，取一行数据，最后IFNULL判断是否为空

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare M int;
set M=N-1;
  RETURN (
      # Write your MySQL query statement below.
    select IFNULL(
        (select Salary from Employee group by Salary order by Salary desc limit M,1),
        NULL)
  ); 
END
```