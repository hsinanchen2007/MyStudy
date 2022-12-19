### 解题思路


### 代码

```mysql
# Write your MySQL query statement below
select *
from cinema c
where c.description!='boring'
and c.id%2=1
order by rating desc

```