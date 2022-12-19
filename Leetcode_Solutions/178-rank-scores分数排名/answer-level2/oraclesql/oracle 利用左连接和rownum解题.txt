select s1.Score,s2.rank from Scores s1 left join (
    select Score, rownum rank from (select distinct Score from Scores order by Score desc)) s2 
    on s1.Score=s2.Score;