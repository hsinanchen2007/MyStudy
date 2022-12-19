使用窗口函数问题就变得简单了很多，但是leetcode的版本不支持，可以本地ide试一下，思路也好理解
select 
	e.id
    ,e.month
	,sum(e.salary) over(partition by id order by e.month)  as salary
from employee e join 
(select id,max(month) as month from employee group by id) m
on e.id=m.id and e.month<>m.month
order by e.id,e.month desc;