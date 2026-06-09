select t.Request_at as Day, 
    round(sum(if(t.status in ('cancelled_by_driver','cancelled_by_client'),1,0))/count(*),2) as 'Cancellation   Rate' 
from trips t
where 
    not exists (select null from users u where t.Client_Id=u.users_Id and u.banned='yes') 
and  
    not exists (select null from users u where t.Driver_Id=u.users_Id and u.banned='yes')
and 
    t.Request_at between date('2013-10-1') and date('2013-10-3')
group by
t.Request_at
