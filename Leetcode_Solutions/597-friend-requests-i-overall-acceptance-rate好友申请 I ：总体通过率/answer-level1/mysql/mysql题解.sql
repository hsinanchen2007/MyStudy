select 
ifnull(Round(
    count(distinct R.requester_id,R.accepter_id)/count(distinct F.sender_id,F.send_to_id),2
),0.0) accept_rate
from friend_request F,request_accepted R