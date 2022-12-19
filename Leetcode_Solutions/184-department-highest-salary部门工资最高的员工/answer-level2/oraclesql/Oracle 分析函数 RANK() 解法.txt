
```sql
SELECT 
    t.Department,
    t.Employee,
    t.Salary
FROM (
    SELECT 
        d.name Department,
        e.name Employee,
        e.Salary,
        -- 对部分分区，按照薪资降序排列，求排名
        rank() OVER(partition by e.DepartmentId ORDER BY e.Salary DESC) rank
    FROM Employee e JOIN Department d ON e.DepartmentId = d.Id) t
WHERE t.rank = 1;
```