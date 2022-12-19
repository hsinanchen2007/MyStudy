select e.Name as Employee from Employee e, Employee l
where e.ManagerId = l.Id and e.salary > l.salary