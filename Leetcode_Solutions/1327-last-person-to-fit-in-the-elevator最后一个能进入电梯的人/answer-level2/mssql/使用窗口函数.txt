```
select top 1 person_name from(
    select person_name,turn,sum(weight) over(order by turn) addup_weight
    from Queue a
) t where addup_weight<=1000
order by turn desc
```
