### 解题思路
先找出至少有5名直接下属的经理id，再与employee表连接找出该经理对应的名字

### 代码

```mysql
# Write your MySQL query statement below
SELECT
    Name
FROM
    Employee AS t1 JOIN
    (SELECT
        ManagerId
    FROM
        Employee
    GROUP BY ManagerId
    HAVING COUNT(ManagerId) >= 5) AS t2
    ON t1.Id = t2.ManagerId
;




```