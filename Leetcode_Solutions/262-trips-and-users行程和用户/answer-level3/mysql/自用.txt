select temp1.Day as Day,
if(temp2.Counts is null,0.00,truncate(temp2.Counts/temp1.Counts,2)) as "Cancellation Rate"
from
(select t.Request_at as Day,count(1) as Counts
from Trips as t inner join Users as u
on t.client_Id = u.Users_Id and u.Banned = "No"
group by t.Request_at) as temp1
left join
(select t2.Request_at as Day,count(1) as Counts
from (select * from Trips where Status <> "completed") as t2 inner join Users as u2
on t2.client_Id = u2.Users_Id and u2.Banned = "No"
group by t2.Request_at) as temp2
on temp1.Day = temp2.Day