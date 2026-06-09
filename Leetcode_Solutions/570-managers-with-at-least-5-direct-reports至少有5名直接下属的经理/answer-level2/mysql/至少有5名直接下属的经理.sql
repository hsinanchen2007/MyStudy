####  方法：使用临时表进行连接
**算法：**
- 首先，我们只需使用此 `ManagerId` 列就可以获取拥有 5 个以上直接下属的经理的 ID。             
- 然后，我们可以通过将该表与 `Employee` 表连接来获取该经理的名称。 

```MySQL [ ]
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