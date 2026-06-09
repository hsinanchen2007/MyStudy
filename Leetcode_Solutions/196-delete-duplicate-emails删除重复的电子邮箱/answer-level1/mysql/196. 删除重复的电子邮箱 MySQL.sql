### 解题思路
1.表与自身连接，以Email相同的做连接，再将Email相同的但Id大的做删除操作。

### 代码

```mysql
# Write your MySQL query statement below

DELETE p1.*
FROM Person p1,Person p2
WHERE p1.Email = p2.Email AND p1.Id > p2.Id
```