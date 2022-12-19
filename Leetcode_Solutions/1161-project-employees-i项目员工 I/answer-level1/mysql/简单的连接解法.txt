SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM Project t1, Employee t2
WHERE t1.employee_id = t2.employee_id
GROUP BY 1