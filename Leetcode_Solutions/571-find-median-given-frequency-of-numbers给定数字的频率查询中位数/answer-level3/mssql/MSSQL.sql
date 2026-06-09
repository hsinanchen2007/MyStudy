```
select avg(cast(number as float)) as median
from (select number, Frequency, sum(Frequency) over(order by Number ASC) as sumasc, sum(Frequency) over(order by Number DESC) sumdesc from Numbers) temp
where Frequency >= abs(sumasc - sumdesc)
```
