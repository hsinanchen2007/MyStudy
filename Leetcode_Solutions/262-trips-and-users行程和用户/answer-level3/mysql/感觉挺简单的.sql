``` MySQL
select Day, round(total_cancel/total, 2) as 'Cancellation Rate' from (select Request_at as Day, sum(if(Status != 'completed', 1, 0)) as total_cancel, count(*) as total from Trips where Client_Id not in (select Users_Id from Users where Banned = 'yes') and Request_at between '2013-10-01' and '2013-10-03' group by Request_at
) b;
```
