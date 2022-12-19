# Write your MySQL query statement below
select Request_at as Day, round(sum(if(Status ='completed',0,1))/count(*),2) as 'Cancellation Rate'
from Trips a, Users b , Users c
where a.Client_Id = b.Users_Id
and b.Banned = 'No'
and a.Driver_Id = c.Users_Id
and c.Banned = 'No'
group by Request_at