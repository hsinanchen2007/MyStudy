select sc.Score as Score, rs.rank as rank
from
    --排序，类似oracle的row_number
    (select @rank := @rank+1 as rank,Score
     from
        --自定义变量
        (select @rank := 0)
     as r,
        --不重复分数进行排序
        (select distinct Score
            from Scores ORDER BY Score DESC )
     as s)
as  rs,
    (select Score
        from Scores ORDER BY Score DESC )
as sc
where sc.Score=rs.Score