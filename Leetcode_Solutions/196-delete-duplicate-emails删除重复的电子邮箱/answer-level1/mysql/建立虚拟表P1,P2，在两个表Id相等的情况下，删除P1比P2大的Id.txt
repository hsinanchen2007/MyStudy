### 解题思路
建立虚拟表P1,P2，在两个表Id相等的情况下，删除P1比P2大的Id

### 代码

```mysql
# Write your MySQL query statement below

DELETE P1
FROM Person AS P1,Person AS P2
WHERE P1.Email=P2.Email AND P1.Id>P2.Id
```