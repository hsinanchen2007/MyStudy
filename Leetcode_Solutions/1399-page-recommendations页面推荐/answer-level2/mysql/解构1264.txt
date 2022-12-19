按照题目描述“向user_id = 1的用户，推荐其朋友们...“，按照理解存在两种可能：user_id = 1是其他用户的朋友和其他用户是user_id = 1的朋友，因此就要在user1_id列和user2_id分别找出值为1的数据，并使用UNION ALL联合数据。
```
SELECT 
    user2_id AS user_id
FROM
    Friendship
WHERE
    user1_id = 1 UNION ALL SELECT 
    user1_id AS user_id
FROM
    Friendship
WHERE
    user2_id = 1
```
ok，已经找出了user_id = 1的用户所有朋友，那么就可以在Likes表中查出这些朋友喜欢的页面。又因为不要推荐user_id = 1的用户已经喜欢的页面，所以还要在Likes表中排除user_id = 1的数据。
```
SELECT DISTINCT
    page_id
FROM
    Likes
WHERE
    user_id IN (SELECT 
            user2_id AS user_id
        FROM
            Friendship
        WHERE
            user1_id = 1 UNION ALL SELECT 
            user1_id AS user_id
        FROM
            Friendship
        WHERE
            user2_id = 1)
        AND page_id NOT IN (SELECT 
            page_id
        FROM
            Likes
        WHERE
            user_id = 1)
```