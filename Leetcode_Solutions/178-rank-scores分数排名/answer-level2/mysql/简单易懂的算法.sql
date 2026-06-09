### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select Score,Rank
from(
    select Score,@curRank:=if(@prev=Score,@curRank+0,@curRank+1) as Rank,@prev:=Score
    from (select * from Scores order by Score desc) as s,(select @curRank:=0,@prev:=-1) as r
) as n
```