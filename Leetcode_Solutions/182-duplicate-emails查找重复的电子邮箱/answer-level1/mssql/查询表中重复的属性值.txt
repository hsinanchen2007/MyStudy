### 解题思路
给Person表取别名P1,P2,找出2表中属性Id值不同但Email值相同的元组，然后取其Email属性值。

### 代码

```mssql
/* Write your T-SQL query statement below */
SELECT DISTINCT P1.Email FROM Person AS P1, Person AS P2 WHERE P1.Email=P2.Email AND p1.Id!=p2.id;
```