

```sql
select
    seat_id
from
    (select
        seat_id,
        count(1) over (partition by offset) cnt
    from
        (select
            seat_id,
            (row_number() over (order by seat_id) - seat_id) offset
        from cinema
        where free = 1
        )
    )
where cnt >= 2 -- 2改为N，可实现查找任意N个座位连续的记录。
order by seat_id
```
