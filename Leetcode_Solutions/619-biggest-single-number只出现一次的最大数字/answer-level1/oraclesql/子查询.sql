```
/* Write your PL/SQL query statement below */
select nvl(max(num),null) num
from (
    select distinct num,count(*) over(partition by num) cnt
    from my_numbers)
where cnt=1;
```
