```
select
	seller_id
from
	(select
		seller_id,
		rank() over(order by sum(price) desc) rn
	from sales
	group by seller_id)
where rn = 1
```
