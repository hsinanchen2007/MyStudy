### 解题思路
1. 描述不是boring，所以就是not like "%boring%"，对id取模2运算得到余数等于1则为奇数。

### 代码

```mysql
# Write your MySQL query statement below
SELECT *
FROM  cinema
WHERE description NOT LIKE "%boring%" AND mod(id,2) = 1
ORDER BY rating DESC
```