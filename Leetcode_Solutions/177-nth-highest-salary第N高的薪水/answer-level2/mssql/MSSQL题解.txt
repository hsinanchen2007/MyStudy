### 解题思路
    对salary分组再salary倒叙排序，返回第二行数据

### 代码

```mssql
CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        select salary from 
        (select row_number()over(order by salary desc) as flag,salary 
        from employee
        group by salary )a
        where a.flag = @N
    );
END
```