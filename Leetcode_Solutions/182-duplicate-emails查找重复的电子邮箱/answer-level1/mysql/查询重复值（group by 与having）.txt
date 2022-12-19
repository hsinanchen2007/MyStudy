### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select  Email
from Person
group by Email
having count(Email)>1;

```
重复的值一意味着count（字段）大于1，可以使用临时表，获取到count（字段）as num
where num >1 然后得到有重复的email；
或者使用group by与having 分组后在做条件约束；