```
# Write your MySQL query statement below
SELECT DISTINCT page_id AS recommended_page
FROM Likes
WHERE user_id IN (SELECT (CASE WHEN user1_id = 1 THEN user2_id WHEN user2_id=1 THEN user1_id END) AS id
    FROM Friendship
    WHERE user1_id = 1 or user2_id = 1)
AND page_id NOT IN (SELECT page_id FROM Likes WHERE user_id = 1)
```
利用 case when条件句挑出所有user_1的朋友，然后用user_id IN (...) 将朋友们喜欢的page从likes中找出，并注意去除掉user_1本身喜欢的page