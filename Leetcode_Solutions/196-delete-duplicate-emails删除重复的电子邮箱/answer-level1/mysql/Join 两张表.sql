### 解题思路
Join 两张表找出有重复Email的行
执行用时 :
600 ms, 在所有 MySQL 提交中击败了72.64%的用户
### 代码

```mysql
# Write your MySQL query statement below
DELETE FROM Person
Where Id In
    (SELECT Id
    FROM (
        SELECT P2.Id as Id
        FROM Person as p2, Person as P1
        WHERE P2.Id>P1.Id AND P2.Email=P1.Email) as p);
```