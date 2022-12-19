执行结果：
通过
显示详情
执行用时 :
141 ms
, 在所有 mysql 提交中击败了
80.54%
的用户
```
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set n=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select ifnull((select distinct salary from employee order by salary desc limit n,1),null)
  );
END
```
