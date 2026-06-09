### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select distinct l1.num as ConsecutiveNums 
from Logs l1 inner join Logs l2 inner join Logs l3
on l1.num = l2.num and l2.num =l3.num and l1.id = l2.id-1 and l2.id = l3.id -1


```