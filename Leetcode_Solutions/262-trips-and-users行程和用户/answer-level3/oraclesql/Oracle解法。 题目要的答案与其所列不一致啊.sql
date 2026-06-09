select b.day, to_char(round(nvl(a.num1,0)/b.num2,2),'f***99990.00') as "Cancellation Rate"   --
from
(select 
Request_at as day,
count(t1.id) num2
from
trips t1
left join
users t2
on t1.Client_Id=t2.users_id     --乘客
left join
users t3
on t1.driver_id=t3.users_id     --司机取消
where t2.banned='No'
and t3.banned='No'
group by Request_at)b
left join
(select 
Request_at as day,
count(t1.id) num1
from
trips t1
left join
users t2
on t1.Client_Id=t2.users_id     --乘客
left join
users t3
on t1.driver_id=t3.users_id     --司机取消
where (t1.status='cancelled_by_driver' or t1.status='cancelled_by_client')
and t2.banned='No'
and t3.banned='No'
group by Request_at)a
on b.day=a.day
order by b.day