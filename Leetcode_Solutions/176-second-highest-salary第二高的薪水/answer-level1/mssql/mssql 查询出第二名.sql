### 解题思路
此处撰写解题思路
读题-第二大使用函数max；
多角度-存在无第二大的情况nullif;
优化-nullif 内置函数，order by除非另外还指定了 TOP 或 FOR XML，否则，ORDER BY 子句在视图、内联函数、派生表、子查询和公用表表达式中无效。

### 代码

```mssql
/* Write your T-SQL query statement below */
SELECT  NULLIF(( SELECT max(salary)
                 FROM   employee
                 WHERE  salary < ( SELECT   MAX(salary)
                                   FROM     employee
                                 )
               ), NULL) AS SecondHighestSalary;

```