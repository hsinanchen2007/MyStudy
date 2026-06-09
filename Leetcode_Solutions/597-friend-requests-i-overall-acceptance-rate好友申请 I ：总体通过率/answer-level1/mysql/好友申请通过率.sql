#要考虑到分母为0的情况，这种时候会返回null,用ifnull来避免这种情况
select ifnull(round(count(distinct a.requester_id,a.accepter_id) / count(distinct b.sender_id,b.send_to_id),2),0) as accept_rate
from request_accepted a,friend_request b