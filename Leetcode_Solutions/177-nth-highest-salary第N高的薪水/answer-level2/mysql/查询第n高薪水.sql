### 解题思路
distinct 去重
利用limit定位第n个（limit （n-1），1）
ifnull 当没有结果集时返回null

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
   declare p int;
   set p=n-1;
  RETURN (
      # Write your MySQL query statement below.
      
      select ifnull((select distinct salary from employee order by salary desc limit 1 offset p ) ,null) as NHighestSalary
      
  );
END
```