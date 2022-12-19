## 基础知识
sql语句中，使用@来定义一个变量。如：@abc
sql语句中，使用:=来给变量赋值,：@abc:=123,则变量abc的值为123

## 第一部分
排序去重
```sql
select 
distinct Score
from 
Scores
order by Score desc
```

## 第二部分
加上rank的索引
```sql
select
    s.Score,
    cast(@curRank:=@curRank+1 as signed) as Rank
    from
    (
        select 
        distinct Score
        from 
        Scores
        order by Score desc
    )s,
(select @curRank := 0) r
```

## 第三部分
原表左连接搞定
```sql
select
s.Score,
t.Rank
from 
Scores s
left join
(
    select
    s.Score,
    cast(@curRank:=@curRank+1 as signed) as Rank
    from
    (
        select 
        distinct Score
        from 
        Scores
        order by Score desc
    )s,
    (select @curRank := 0) r
)t
on
s.Score = t.Score
order by
s.Score desc;
```
