这题里面唯一好玩的在于怎么取奇数, 有 id %2 = 1的普通操作, 还有按位与 &1 这种
```
SELECT id,movie,description,rating
FROM cinema
WHERE id%2 = 1 AND description != 'boring' ORDER BY rating DESC;
```