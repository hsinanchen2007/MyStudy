1. 去重
2. 排序
3. 获取第二个
4. 空时设置返回NULL
```
# Write your MySQL query statement below
select ifnull (
    (select DISTINCT Salary from Employee order by Salary desc limit 1,1),NULL)
as SecondHighestSalary
```
