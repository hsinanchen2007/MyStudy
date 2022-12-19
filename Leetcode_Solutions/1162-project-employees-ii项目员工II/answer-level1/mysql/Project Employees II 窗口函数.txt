### 解题思路
Mysql和 MSSQL 通用， Mysql 客户端可以完美运行，这里却不行。排序问题可以多考虑窗口函数

### 代码

```mssql
/* Write your T-SQL query statement below */
select project_id
from(
select project_id, dense_rank() over(order by count(p.employee_id) desc) as 'num'
from project p join employee e
on p.employee_id = e.employee_id
group by project_id
) t
where t.num = 1
```