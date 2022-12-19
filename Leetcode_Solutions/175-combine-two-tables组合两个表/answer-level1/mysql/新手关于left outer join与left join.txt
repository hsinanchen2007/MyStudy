### 解题思路
新手，才看完《mysql必知必会》的水平。
条件：无论person是否有地址信息，都需要基于两表提供person的信息，故而选择left outer join。
个人涉及到的问题：left outer join 与left join有什么区别
查找资料：left outer join 与left join没有区别，left join是left outer join的简写。
结论：没区别！没想到吧！哈哈
### 代码

```mysql
# Write your MySQL query statement below
select firstname,lastname,city,state
from person left outer join address
on person.personid = address.personid;
```