用子查询先分组查出只出现了一次的数字，再取这些数中的max
```
select max(num) as num from 
(
    select num from my_numbers
    group by num
    having count(num) = 1
)as t
;
```
