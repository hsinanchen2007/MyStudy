### 解题思路
1.先按照邮箱来分类，将所有相同的邮箱分成一个组别，在对每一个邮箱进行计数。
2.从邮箱和计数的临时表中选出计数大于1的邮箱即表示重复邮箱。

### 代码

```mysql
# Write your MySQL query statement below
SELECT Email
FROM
(SELECT Email,COUNT(Email) AS num
FROM Person
GROUP BY Email
) AS statistic
WHERE num > 1
```