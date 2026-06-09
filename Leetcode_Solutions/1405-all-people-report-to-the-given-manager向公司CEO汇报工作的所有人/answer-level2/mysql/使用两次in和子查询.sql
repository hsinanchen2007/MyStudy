# Write your MySQL query statement below
SELECT employee_id 
FROM employees 
WHERE manager_id IN (SELECT employee_id FROM employees WHERE manager_id IN ( SELECT employee_id FROM employees WHERE manager_id = 1 )) 
AND employee_id != 1;