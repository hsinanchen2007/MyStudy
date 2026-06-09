### 解题思路
此处撰写解题思路
使用两个join，进行联表查询，连续的含义：使得t1表的id=t2.id-1，且等于t3表的id-2，符合条件的便是连续出现3次以上，若次数过多，此方法有待优化
### 代码

```mysql
# Write your MySQL query statement below
select 
    t1.Num as ConsecutiveNums 
from 
(
    select 
        Num
        ,Id
    from 
        Logs
    order by Id ASC
) t1
join
(
    select 
        Num
        ,Id
    from 
        Logs
    order by Id ASC
) t2 
on 
    t1.Num = t2.Num and t1.id = t2.id-1
join
(
    select 
        Num
        ,Id
    from 
        Logs
    order by Id ASC
) t3 
on 
    t1.Num = t3.Num and t1.id = t3.id-2
where 
    t3.Num is not null
group by 
    t1.Num
```