select s.Score, t.rownum as Rank
  from Scores as s
    left join (
        #这里自己做了个表将成绩降序排列，然后加上row_number
        select f.Score as Score,  @rownum:=@rownum+1 AS rownum
          from (SELECT @rownum:=0) r,
          (
              select distinct Score from Scores order by Score desc
          ) as f
    ) as t on s.Score = t.Score order by t.Score desc;