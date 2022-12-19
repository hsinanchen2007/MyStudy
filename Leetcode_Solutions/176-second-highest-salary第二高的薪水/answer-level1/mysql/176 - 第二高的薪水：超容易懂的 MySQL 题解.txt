> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```mysql
SELECT max(Salary)  as SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT max(Salary) FROM Employee)
```
