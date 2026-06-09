select
    distinct page_id as recommended_page
from
    likes
where 
    user_id in
    (select user2_id from friendship where user1_id=1
     union
     select user1_id from friendship where user2_id=1)
and
    page_id not in
    (select page_id from likes where user_id=1)