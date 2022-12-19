### 执行用时
132 ms

### 解题思路
1.去重
2.排序
3.limit

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE c INT default if(N>0,N-1,1);
  RETURN (
      # Write your MySQL query statement below.
      select Salary from Employee group by Salary order by Salary desc limit c,1
  );
END
```