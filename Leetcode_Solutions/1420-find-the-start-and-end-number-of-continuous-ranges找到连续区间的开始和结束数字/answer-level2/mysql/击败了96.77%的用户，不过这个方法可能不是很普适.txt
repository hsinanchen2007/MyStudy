``` []
select * from
(
    (select log_id as start_id 
    from Logs
    where log_id not in (select log_id + 1 from Logs)
    ) as t1
left join 
    (select log_id as end_id 
    from Logs
    where log_id not in (select log_id - 1 from Logs)
    ) as t2
on t1.start_id <= t2.end_id
) 
group by start_id
```


