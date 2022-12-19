```
SELECT employee_id
FROM Employees
WHERE manager_id IN (SELECT employee_id
                     FROM Employees
                     WHERE manager_id IN (SELECT employee_id
                                         FROM Employees
                                         WHERE manager_id = 1))
    AND employee_id != 1
```
