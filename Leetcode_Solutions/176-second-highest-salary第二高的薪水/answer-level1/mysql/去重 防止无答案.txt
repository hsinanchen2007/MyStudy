### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
# Write your MySQL query statement below
select
 ifNull(
     (select distinct salary #remove duplicates
     from Employee order by Salary Desc
     limit 1,1),null #use ifnull to avoid that there is no second largest value, if limit's offset overflow it will return empty(not null)
 ) as SecondHighestSalary;

```