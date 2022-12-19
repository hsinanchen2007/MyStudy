min聚合 + group by

代码：
```
# Write your MySQL query statement below
select player_id, min(event_date) as first_login
from Activity
group by player_id
```

sql存在的聚合函数如下：
–COUNT：统计行数量
–SUM：获取单个列的合计值
–AVG：计算某个列的平均值
–MAX：计算列的最大值
–MIN：计算列的最小值

参考文献：
1. SQL语句汇总（三）——聚合函数、分组、子查询及组合查询 [https://www.cnblogs.com/ghost-xyx/p/3811036.html]()