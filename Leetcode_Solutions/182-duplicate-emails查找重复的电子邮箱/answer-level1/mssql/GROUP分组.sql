找重复的邮箱就是出现次数大于1所以使用GROUP配合HAVING
/* Write your T-SQL query statement below */
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1