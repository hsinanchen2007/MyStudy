select request_at as Day,
round(sum(case when status = "completed" then 0 else 1 end)/count(*),2) as "Cancellation Rate"
from trips where client_id not in 
(select users_id from users where banned ="yes") and driver_id not in 
(select users_id from users where banned ="yes") and request_at between "2013-10-01" and "2013-10-03" group by request_at;
执行用时 : 363 ms, 在Trips and Users的MySQL提交中击败了95.01% 的用户