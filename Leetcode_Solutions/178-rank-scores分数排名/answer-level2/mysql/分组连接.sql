select s.Score ,t3.Rank from Scores s left join (
    select Score , cast(@rank:= @rank + 1 as signed) as Rank from 
        (select Score from Scores group by Score order by Score desc) t1,
            (select @rank := 0) t2
)t3 on s.Score = t3.Score order by s.Score desc;

1.先把得分分组(去重也可以),按倒序排序,设置排名
2.关联查询->同样的分数同样的排名