```
# Write your MySQL query statement below
SELECT 
    Name Employee #列名
FROM
    Employee AS a #表名

--  SQL SELECT 语法
-- SELECT column_name,column_name
-- FROM table_name;

WHERE
    Salary > (SELECT # > 是本题的灵魂
                    Salary
                FROM
                    Employee
                WHERE
                    Id = a.Managerid)

-- SQL WHERE 语法
-- SELECT column_name,column_name
-- FROM table_name
-- WHERE column_name operator value;

-- operator
-- = 	等于
-- <> 	不等于。注释：在 SQL 的一些版本中，该操作符可被写成 !=
-- > 	大于
-- < 	小于
-- >= 	大于等于
-- <= 	小于等于
-- BETWEEN 	在某个范围内
-- LIKE 	搜索某种模式
-- IN 	指定针对某个列的多个可能值

```
