#### 思路 ####
简单直观的解法，没有什么特殊技巧：
- `useractivity`根据`username`自连接
- 按照`username`和`startdate`分组
- `having`筛选分组
  - 用`sum()`统计分组中`startdate`比当前更靠后的记录数，若为`1`，则是最近的第二次活动
  - 如果分组中记录只有一条，根据题意也要选出来
#### 代码 ####
```mysql []
select u1.*
from useractivity u1 join useractivity u2
on u1.username = u2.username
group by u1.username, u1.startdate
having sum(u2.startdate > u1.startdate) = 1 or count(1) = 1
```
