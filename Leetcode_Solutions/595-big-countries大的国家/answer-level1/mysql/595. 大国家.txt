耗时280 ms, 在所有 MySQL 提交中击败了94.76%的用户

select name, population, area
from World
where (population/10000 > 2500 or area/10000 > 300);