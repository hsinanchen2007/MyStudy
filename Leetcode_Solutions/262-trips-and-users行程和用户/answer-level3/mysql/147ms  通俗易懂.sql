```
select
        t.request_at `day`,
        cast( count(if(locate('cancelled',t.status),true,null))/count(1) as decimal(10,2)) `Cancellation Rate`
    from
        Trips t
    where 
        t.request_at >= '2013-10-01' and t.request_at <= '2013-10-03'
        and 
        t.client_id in(select concat_ws(',',users_id) us from  Users where Banned='No')  
        and   
        t.driver_id in(select concat_ws(',',users_id) us from  Users where Banned='No')
    group by
        t.request_at
```
