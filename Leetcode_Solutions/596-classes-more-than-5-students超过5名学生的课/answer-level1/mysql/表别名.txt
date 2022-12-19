#别名会提高运行速度，运行速递提高224ms。一般都是二次运行，但本题中是第一次查询，不太清楚原因。

select a.class from courses a
group by a.class 
having count(distinct a.student ) >=5


