### 解题思路
含义见注释

### 代码

```mysql
# Write your MySQL query statement below
select
    #convert函数转换两位小数
    convert(
        count(distinct (a1.player_id))/(select count(distinct player_id) from Activity ) ,
        decimal(10,2)
    )
    as fraction
    
from 
    Activity a1,
    #找到每个id的最小日期
     (select player_id,min(event_date) as mindate from Activity  group by player_id ) as mint
where
    #当前日期与最小日期做差=1且id相同
    DateDiff(a1.event_date,
    mint.mindate
    )=1
    and
    a1.player_id=mint.player_id;
```