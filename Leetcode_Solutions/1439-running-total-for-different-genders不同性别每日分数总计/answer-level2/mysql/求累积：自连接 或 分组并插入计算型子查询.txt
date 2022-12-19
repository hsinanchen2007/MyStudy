# Write your MySQL query statement below
#方法1：拆分表+自连接
#（1）计算每个性别每天的分数 t1
#（2）t1自连接t2，分组查询
#（3）最终结果
/*
select t1.gender,t1.day,sum(t2.score) total
from
(select gender,day,sum(score_points) score
from Scores
group by gender,day
order by gender,day) t1,
(select gender,day,sum(score_points) score
from Scores
group by gender,day
order by gender,day) t2
where t1.gender=t2.gender
and t2.day<=t1.day
group by t1.gender,t1.day
order by t1.gender,t1.day
*/
#方法2：自连接
/*
select s1.gender,s1.day,sum(s2.score_points) total
from Scores s1,Scores s2
where s1.gender=s2.gender and s2.day<=s1.day
group by s1.gender,s1.day
*/
#方法3:分组+计算型子查询
select s1.gender,s1.day,(select sum(score_points) from Scores s2 where s2.gender=s1.gender and s2.day<=s1.day)total
from Scores s1
group by s1.gender,s1.day