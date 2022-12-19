两表内联查询。a表视为员工，b表视为经理 当a的经理id = b的员工id 且 a的工资大于b的工资
select a.name as employee from employee a,employee b where a.ManagerId = b.Id and a.salary>b.salary