### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select distinct Num ConsecutiveNums
from
(select a.Num Num,count(b.Num) 总数 
from 
Logs a join Logs b 
on
b.Id-a.Id >=0 and b.Id-a.Id <=2 and a.Num=b.Num
group by a.Id
)t
where t.总数>=3
```