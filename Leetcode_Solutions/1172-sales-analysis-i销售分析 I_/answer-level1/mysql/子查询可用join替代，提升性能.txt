# 子查询做法:先将最高价格查出来，再用子查询取出seller_id
```
 SELECT 
    seller_id 
 FROM 
    Sales 
 GROUP BY 
    seller_id
 HAVING 
    SUM(price) = (
                    SELECT 
                        SUM(price)
                    FROM 
                        Sales
                     GROUP BY 
                        seller_id
                     ORDER BY 
                        SUM(price) DESC
                     LIMIT 1
                )

```
# join做法:将子查询的结果用right join代替，join条件是价格相等
```
SELECT 
    seller_id 
FROM
    (
        SELECT
            seller_id ,
            SUM(price) AS P1
        FROM 
            Sales 
        GROUP BY 
            seller_id
    ) AS T1
    RIGHT JOIN
    (
        SELECT 
            SUM(price) AS P2
        FROM 
            Sales
        GROUP BY 
            seller_id
        ORDER BY 
            P2 DESC
        LIMIT 1
    ) AS T2
    ON T1.P1 = T2.P2
```
