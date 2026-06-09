去掉最高的，剩下的里面最高的就是第二高

代码：
```
select max(salary) as secondhighestsalary from employee
where salary not in
(select max(salary) from employee)
```
