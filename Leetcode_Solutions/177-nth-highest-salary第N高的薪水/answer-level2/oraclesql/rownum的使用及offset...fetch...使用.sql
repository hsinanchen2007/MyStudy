### 解题思路
1. 倒序排序，查询出前n条数据
2. 过滤掉前n-1条数据，只取第n条数据

### 代码

```oraclesql
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    Select nvl(b.Salary,null) into result from(
        select rownum rn,salary from (select distinct salary from Employee order by Salary desc) a where rownum<=N) b where b.rn>N-1;
    --oracle 12c后支持offset...fetch...这种方式。想当于limit...offset...
    --Select salary into result from Employee order by Salary desc offset N rows fetch 1 rows only;
    RETURN result;
 
END;
```