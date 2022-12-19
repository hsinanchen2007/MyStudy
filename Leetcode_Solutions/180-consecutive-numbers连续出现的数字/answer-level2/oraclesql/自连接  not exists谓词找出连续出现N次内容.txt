前提: id字段是连续的
支持数据库: mysql / sqlserver / db2 / oracle (ps: 没有特定的数据库实现)


```
# 考虑id连续
select 
    distinct l1.num as 'ConsecutiveNums'
from Logs l1, Logs l2
where l2.Id = l1.Id + 2
and l2.num = l1.num    
and not  exists (
    select * 
    from Logs l3
    where l3.id between l1.id and l2.id
    and  l3.num <> l1.num
)
```
运行时间:
![image.png](https://pic.leetcode-cn.com/5c8d71ce92cf1d1fad730d10d8c4f60abcfc28d8aa69d13a191d5cab310d5b75-image.png)




