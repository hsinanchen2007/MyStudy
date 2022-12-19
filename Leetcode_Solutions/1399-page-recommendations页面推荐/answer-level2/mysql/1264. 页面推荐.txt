1.注意一下Friendship关系是互相的, 用6是1的好友表明1也是6的好友
2.对结果集需要去重
```
select
    distinct page_id as recommended_page
from
    Likes
where
    user_id 
in (select user2_id from Friendship where user1_id = 1
    union
    select user1_id from Friendship where user2_id = 1)
and page_id not in (select page_id from Likes where user_id = 1)

```