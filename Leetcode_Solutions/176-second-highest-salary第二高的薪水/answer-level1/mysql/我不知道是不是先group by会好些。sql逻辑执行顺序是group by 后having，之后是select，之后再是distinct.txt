### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select ifnull((select  Salary    from Employee group by Salary order by Salary desc limit 1,1), null) SecondHighestSalary


```