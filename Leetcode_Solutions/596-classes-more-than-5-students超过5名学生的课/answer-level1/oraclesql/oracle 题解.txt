方法一（自己写）：
select a.class 
from 
(select c.class,count(c.class) cou 
from 
(select distinct * from courses) as c
group by c.class) as a 
where a.cou>=5

写的有点长哈哈哈
先清除重复项 作为临时表
获取 课程数 和 课程名 作为临时表
再判断

方法二（参考别人的）：
select c.class 
from courses c
group by c.class
having count(distinct(c.student))>=5

省时，省力，别人的真香
