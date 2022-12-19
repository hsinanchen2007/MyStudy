```
select business_id
from Events as a
left join
    (select event_type, avg(occurences) as eveAvg
    from Events
    group by event_type) as b
on a.event_type = b.event_type
where a.occurences > b.eveAvg
group by business_id
having count(*) >= 2;
```

切勿用子查询，会超时的。。
