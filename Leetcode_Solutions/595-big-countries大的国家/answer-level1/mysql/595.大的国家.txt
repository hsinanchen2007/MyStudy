```
select
    name,
    population,
    area
from
    World
where
    (area > 3000000 or population > 25000000)
;
```
执行用时 :291 ms, 在所有 MySQL 提交中击败了88.93% 的用户
