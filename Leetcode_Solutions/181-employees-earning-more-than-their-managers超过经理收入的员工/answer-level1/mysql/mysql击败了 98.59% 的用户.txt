#没有经理时，不会满足第二个条件，有经理时，对比
#不需要表连接，

select e1.Name Employee from Employee e1,Employee e2
where e1.Salary>e2.Salary and e2.Id=e1.ManagerId 