### 解题思路
limit A offset B 跳过B条数据读取其后的A条数据
ifnull(A,B) 如果A是空则返回B，否则就返回A

### 代码

```mysql
# Write your MySQL query statement below
select (
    ifnull(
   ( select distinct salary 
    from employee
    order by salary desc
    limit 1 offset 1),
    null)
) as SecondHighestSalary;
```