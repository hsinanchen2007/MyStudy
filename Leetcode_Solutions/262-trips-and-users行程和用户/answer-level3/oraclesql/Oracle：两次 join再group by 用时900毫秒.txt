```
select a.request_at Day,round(sum(decode(a.status,'completed',0,1))/count(1),2) "Cancellation Rate" 
from Trips a
left join Users b
on (a.client_id = b.users_id and b.role = 'client')
left join Users c
on (a.driver_id = c.users_id and c.role = 'driver')
where b.banned <> 'Yes' and c.banned <> 'Yes' and a.request_at between '2013-10-01' and '2013-10-03'
group by a.request_at
```
