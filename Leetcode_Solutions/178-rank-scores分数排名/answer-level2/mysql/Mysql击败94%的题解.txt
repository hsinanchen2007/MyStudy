思路:先查出每个分数的排名 b，然后再将分数表Scores和排名表b进行关联，得出结果。
注：@rowNum:=@rowNum+1 在这里返回的是小数(在数据库中返回的是整数类型)，将其转为int类型。

select a.Score, cast( b.Rank as SIGNED INTEGER) as Rank
from Scores a
inner join (
    select @rowNum:=@rowNum+1 as Rank, s1.Score  from (
        select Score from Scores group by Score order by Score desc 
    ) s1, (select @rowNum:=0) aa
) b 
on a.Score = b.Score
order by a.Score desc