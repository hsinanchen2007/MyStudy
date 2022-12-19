### 解题思路
利用自己的表和自己的表关联，然后利用id进行筛选，这里id比较重要

### 代码

```mysql
# Write your MySQL query statement below
select distinct l1.num as ConsecutiveNums
from logs as l1,logs as l2,logs as l3
where l2.num = l1.num and l2.num = l3.num
and l2.id = l1.id+1 and l3.id=l2.id+1
```