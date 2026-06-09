
1. b记录上一个Score的值
2. a则代表名次, 用b和这一个Score做比较,如果改变就+1
```sql []
select 
Score,
cast( Rank as SIGNED INTEGER) as 'Rank'
from 
(
    select 
    @a:= case when @b = Score then @a else @a+1 end as 'Rank',
    @b:= Score as 'help',
    Score
    from 
    Scores , (select @a:=0,@b:=null) t1
    order by Score desc
) t

```
