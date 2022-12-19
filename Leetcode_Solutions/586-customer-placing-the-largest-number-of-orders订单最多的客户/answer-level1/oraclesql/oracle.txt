```sql
select customer_number
from (select o.customer_number, count(1)
        from orders o
        group by o.customer_number
        order by count(1) desc
    )
where rownum = 1
```
