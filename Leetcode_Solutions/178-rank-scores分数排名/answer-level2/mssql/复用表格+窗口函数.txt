方法一：
排名排序，需要复用表。
s1主表，s2附表
s1中的成绩，在s2去重的成绩中，有几个比他大？
比如s1(3.5,3.65,4,4);s2(3.5,3.65,4,4)
s1=4时，在s2中有一个值大于等于他，所以s1=4的rank是1；
s1=3.65时，s2中有两个值（3.65，4）大于等于，所以s1=3.65的rank 是2；
代码：
select s1.score,count(distinct s2.score) as Rank
from scores s1,scores s2
where s1.score<=s2.score
group by s1.id
order by s1.score desc;
#注意：一定要加group by否则只会输出s1.score最小的值
上述代码执行顺序：
from >>> where >>> group by >>> select >>> order by
如果不加group by的话，执行完where语句后会直接执行select语句，只会返回最小的s1.core值；
方法二：
窗口函数 dense_rank() over()
select score,dense_rank() over(order by score desc)as Rank
from scores;

