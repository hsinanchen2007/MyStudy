

select d.Score, c.Rank
from scores d
inner join
#先用一个inner join 找到每个分对应的排名；在用第二个inner join把分数和排名投射到每一条记录
#注意第一个inner join用表a的分<=表b的分可得到对应排名
#over
(select a.score,count(b.score) as rank from
(select distinct score from scores) as a
inner join (select distinct score from scores) as b
on a.score<=b.score 
group by a.score) as c
on d.score=c.score
order by d.score desc;