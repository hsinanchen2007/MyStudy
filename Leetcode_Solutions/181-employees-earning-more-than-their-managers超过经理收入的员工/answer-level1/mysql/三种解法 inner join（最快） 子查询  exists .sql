
```
select name as Employee from employee a where salary >
 (select salary from employee where a.managerid = id  ) 
```
执行用时 : 1126 ms, 在Employees Earning More Than Their Managers的MySQL提交中击败了16.76% 的用户

``` 
select name as Employee from employee a where exists
 (select salary from employee where a.managerid = id and a.salary > salary)
 ```
执行用时 : 1518 ms, 在Employees Earning More Than Their Managers的MySQL提交中击败了6.08% 的用户

> 最快
```
select a.name as Employee
from employee a inner join employee b on a.managerid = b.id 
and a.salary > b.salary
```
执行用时 : 577 ms, 在Employees Earning More Than Their Managers的MySQL提交中击败了72.93% 的用户