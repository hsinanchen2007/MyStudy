```


select project_id , Project.employee_id from Project inner join Employee on Project.employee_id = Employee.employee_id where (experience_years,project_id) in (
select max(experience_years) as a ,project_id  from Project inner join Employee on  Project.employee_id = Employee.employee_id group by project_id order by a desc )


```