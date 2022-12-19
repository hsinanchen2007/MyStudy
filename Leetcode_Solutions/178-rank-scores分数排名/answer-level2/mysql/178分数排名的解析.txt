select a.Score, (select count(distinct Score)
                from Scores b
                where b.Score >= a.Score
                ) as rank
from Scores a
order by a.Score desc

重点解释下怎么排序，
(select count(distinct Score)
from Scores b
where b.Score >= a.Score
)

按照这段语句跑的顺序：
第1个a.score 是3.5， 然后我们要选出所有的大于等于3.5 的score，也就依次选出 （3.5, 3.65, 4, 3.85, 4, 3.65 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（3.5， 3.65，4， 3.85），最后用count 就算出了4， 得出id=1 的3.5 的rank 是4.

第2个a.score 是3.65， 然后我们要选出所有的大于等于3.65 的score，也就依次选出 （3.65, 4, 3.85, 4, 3.65 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（ 3.65，4， 3.85），最后用count 就算出了3， 得出id=2 的3.65 的rank 是3.

第3个a.score 是4， 然后我们要选出所有的大于等于4 的score，也就依次选出 （ 4, 4 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（4），最后用count 就算出了1， 得出id=3 的4 的rank 是1.

第4个a.score 是3.85， 然后我们要选出所有的大于等于3.85 的score，也就依次选出 （ 4, 3.85, 4 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（4， 3.85），最后用count 就算出了2， 得出id=4 的3.85 的rank 是2.

第5个a.score 是4， 然后我们要选出所有的大于等于4 的score，也就依次选出 （ 4, 4 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（4），最后用count 就算出了1， 得出id=5 的4 的rank 是1.

第6个a.score 是3.65， 然后我们要选出所有的大于等于3.65 的score，也就依次选出 （3.65, 4, 3.85, 4, 3.65 ），然后因为是distinct score 所以剔除所有重复项，就剩下了（ 3.65，4， 3.85），最后用count 就算出了3， 得出id=6 的3.65 的rank 是3.

最后因为order by a.Score desc， 所以从大到小排序。

