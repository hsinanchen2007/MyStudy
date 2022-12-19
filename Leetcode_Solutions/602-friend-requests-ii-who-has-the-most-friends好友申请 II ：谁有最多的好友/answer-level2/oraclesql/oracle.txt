```
select id as id, ucnt as num
from
(
    select id, count(1) as ucnt
    from
    (
        select requester_id as id from request_accepted
        union all
        select accepter_id as id from request_accepted
    )
    group by id
    order by ucnt desc
)
where rownum = 1
```
