思路是这样的，因为这题要求的是同一个分数排名相同，所以先要计算出不同分数各自的排名，然后将成绩表与这个排名表连接就可以知道每个成绩对应的排名了。
计算不同分数的排名的话就是先select distinct选出不同的分数，然后自连接，通过聚合函数算出有多少大于等于自己的分数，就可以计算出一个排名表了。
然后考虑到会有相同的分数，所以我们拿原表也就是scores表和上面求出的表join一下，就可以的到答案了。
```
--将Scores表与tmp表join一下就可以得到最后所需答案
select Scores.Score, tmp.Rank
from
Scores
left join
(   ---下面是统计每个分数有多少分数比他高，也就是排名，得到tmp表
    select t.Score, count(t.Score)as Rank
    from (
        select a.Score as Score
        from
        (select distinct Score from Scores)as a,
        (select distinct Score from Scores)as b
        where
        a.Score <= b.Score
    )as t
    group by t.Score
)as tmp
on Scores.Score = tmp.Score
order by tmp.Rank asc;
```
