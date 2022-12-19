### 解题思路
既然是要查找重复的，就是要找出现过两次以上的邮箱。
所以先分组统计每个邮箱出现的次数，然后再查找出现过两次以上的邮箱

### 代码

```mysql
# Write your MySQL query statement below

SELECT  Email
FROM Person
GROUP BY Email
HAVING (COUNT(Email)>=2)
```