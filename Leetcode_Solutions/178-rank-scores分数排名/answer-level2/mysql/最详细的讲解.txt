select Score as Score
from Scores;

#将选择出来的命名为a
select a.Score as Score
from Scores as a;

#排序
select a.Score as Score
from Scores as a
order by a.Score DESC;

#比较难的是第二部分。假设现在给你一个分数X，如何算出它的排名Rank呢？ 我们可以先提取出大于等于X的所有分数集合H，将H去重后的元素个数就是X的排名。比如你考了99分，但最高的就只有99分，那么去重之后集合H里就只有99一个元素，个数为1，因此你的Rank为1。 先提取集合H：
select b.Score 
from Scores as b
where b.Score >=X;

#我们要的是集合H去重之后的元素个数，因此升级为：
select count(distinct b.Score) from Scores b where b.Score >= X as Rank;

-- 而从结果的角度来看，第二部分的Rank是对应一部分的分数来的，所以这里的X就是上面的a.Score，
select count(distinct b.Score) from Scores b where b.Score >= a.Score as Rank;

-- 把两部分结合在一起为：
select a.Score  as Score,
(select count(distinct b.Score) from Scores as b where b.Score>=a.score)as Rank
from Scores as a
order by a.Score desc;