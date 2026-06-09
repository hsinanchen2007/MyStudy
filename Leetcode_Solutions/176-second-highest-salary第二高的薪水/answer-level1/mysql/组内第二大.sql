### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select min(salary) as SecondHighestSalary
from employee
where id in (
select s1.id
from employee s1, employee s2
where s1.salary <= s2.salary
group by s1.id
having count(distinct s2.salary) = 2)

子查询里面先看大于等于这个salary的有几个， 如果有超过两个（包括他自己）则返回top2的id， 然后选择较小的那个salary就ok了
```