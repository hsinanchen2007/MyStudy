### 解题思路
目的是将第二高工资 Salary 的用 SecondHightestSalary 列 表示出来
1. 第二高的工资可以先用 DESC 降序排列 工资 Salary,再使用 limit 1,1 或者 limit 1 offset 1 把第二高的工资选择出来
2. 处理 NULL 值可以使用 临时表 或者 ifnull() 函数 处理

### 代码

```mysql
# Write your MySQL query statement below
-- 第一种方法
select
    ifnull(
        (select distinct
            Salary
        from
            Employee
        order by Salary desc limit 1 offset 1),
    NULL) as SecondHighestSalary;
-- 第二种方法
-- select
--     (select distinct 
--         Salary
--     from
--         Employee
--         order by Salary desc limit 1,1) as SecondHighestSalary;
```