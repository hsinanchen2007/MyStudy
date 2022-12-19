

```sql
SELECT project_id
FROM Project
GROUP BY project_id
HAVING COUNT(employee_id) = 
(
SELECT MAX(count_employee_id)
FROM
(
SELECT project_id, COUNT(employee_id) AS count_employee_id
FROM Project
GROUP BY project_id
) As temp
)
```