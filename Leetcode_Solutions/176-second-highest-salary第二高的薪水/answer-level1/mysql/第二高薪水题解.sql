### 解题思路
此处撰写解题思路

1.使用 distinct 来去重有多个第二高薪水人员的情况
2.使用 order by Salary 来降序排列
3.使用 limit 1,1 使用偏移量为 1 取第二条数据
4.使用 IFNULL 来判断是否存在，不存在则返回NULL

### 代码

```mysql
select IFNULL((select distinct(Salary) 
from Employee
order by Salary desc
limit 1,1),null) as SecondHighestSalary
```