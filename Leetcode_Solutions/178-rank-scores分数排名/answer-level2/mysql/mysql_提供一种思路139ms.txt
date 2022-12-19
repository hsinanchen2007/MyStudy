# 我以为会很慢，结果看着还好，87%

select ss.Score AS SCore, temp.num AS Rank
from Scores ss

left join (
    select a.Score,Cast(@i := @i + 1 AS SIGNED  )   AS num
    from (
        select Score
        from Scores
        group by Score 
        order by Score DESC
    ) a,(SELECT @i:=0) as i
    group by a.Score 
    order by a.Score DESC

) temp on ss.Score=temp.Score
order by ss.SCore DESC