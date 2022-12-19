### 解题思路
查就完事儿了 

### 代码

```mysql
# Write your MySQL query statement below
#


select distinct page_id as recommended_page  from Likes where page_id not in (select page_id from Likes where user_id = 1
) and user_id in (select user2_id as frindId from Friendship where user1_id = 1 union all select user1_id as frindId from Friendship where user2_id = 1) 
```