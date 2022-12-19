### 解题思路
1.因为存在部分人员可能不存在地址，所以要用外连接而不是一般的内连接。
2.left join Addrees 左外连接，保持Person表所有数据都在。

### 代码

```mysql
# Write your MySQL query statement below
SELECT FirstName,LastName,City,State
FROM Person left join Address
ON Person.PersonId = Address.PersonId;
```