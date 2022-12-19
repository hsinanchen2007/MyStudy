# Write your MySQL query statement below
select 

(case when q1=0 then round(0,2)

else round(q1/q2,2) end ) accept_rate

from(

select count(*) q1

from(select requester_id,accepter_id

from request_accepted

group by requester_id,accepter_id)t1)t3,

(select count(*) q2

from(select sender_id,send_to_id

from friend_request

group by sender_id,send_to_id)t2)t4