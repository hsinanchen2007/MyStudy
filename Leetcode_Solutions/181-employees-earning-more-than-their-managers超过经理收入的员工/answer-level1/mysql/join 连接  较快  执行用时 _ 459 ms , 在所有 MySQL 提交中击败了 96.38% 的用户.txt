执行用时 : 459 ms , 在所有 MySQL 提交中击败了 96.38% 的用户

先找出员工所属的经理（自连）  再比较 直属员工和经理的  工资

```sql
SELECT                      
	e2. NAME AS Employee                        
FROM
	Employee e1             #经理
JOIN                        
    Employee e2             #员工
WHERE
	e1.Id = e2.ManagerId
AND 
    e2.salary > e1.salary;  #比较工资
```
