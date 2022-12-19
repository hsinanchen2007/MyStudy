### 解题思路
select s1.score score ,count(distinct s2.score) as rank from  scores s1 ,scores s2 
where s1.score<=s2.score
group by s1.score
order by score desc
这是我一开始的写法，但是碍于group by s1.score 会将score相同的部分全部消除掉，出来的结果是去重score之后的，后来这个脑筋怎么也转不过来，过来一想表scores中有ID列，且ID列没有重复的，所以group by之后，正好将score列遍历了一遍，借鉴的评论区大神的意见，简直天才～
### 代码

```mysql
# Write your MySQL query statement below

select a.score , count(distinct b.score) as rank
from scores a,scores b
where a.score <= b.score
group by a.id 
order by a.score  desc


```