#使用or关键字对记录进行条件搜索
select name,population,area
from world
where population>25000000
or area>3000000;
