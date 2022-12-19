select t.Request_at as Day  ,round(sum(Status <> 'completed')/count(*),2) as `Cancellation Rate`
from trips t join users u1 on t.client_id=u1.users_id and u1.role='client'
join users u2 on t.driver_id=u2.users_id and u2.role='driver'
where t.Request_at between '2013-10-01' and '2013-10-03'
and u1.banned <> 'yes'
and u2.banned <> 'yes'
group by t.Request_at