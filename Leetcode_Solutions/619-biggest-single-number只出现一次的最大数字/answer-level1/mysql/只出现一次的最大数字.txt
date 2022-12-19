```
select ifnull(
    (select num
    from my_numbers 
    group by num 
    having count(*) < 2
    order by num desc
    limit 1)
,null) as num;
```