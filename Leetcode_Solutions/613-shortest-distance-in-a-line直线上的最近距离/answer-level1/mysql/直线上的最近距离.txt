__方法   使用FROM多个表自身连接__

__算法__

使用FROM多个表自身连接，where条件table1.x不等于table2.x, 按 绝对差值排序取第一条
```
select abs(p1.x-p2.x) as shortest 
from point p1, point p2
where p1.x<>p2.x
order by shortest
limit 1;
```