方法一：or
select w.name,w.population,w.area 
from world w 
where w.area >3000000 or w.population >25000000

方法二：union
select w.name,w.population,w.area
from world w
where w.area>3000000
union
select w.name,w.population,w.area
from world w
where w.population>25000000

上面一个比较省事但是用到or，额，感觉还是不用or好