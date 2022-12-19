利用JOIN和IN得到包含S8或者iPhone的记录
利用GROUP BY对buyer_id分组
利用COUNT + IF获得每组购买iPhone的记录数（无所谓是否去重）
计数为0的即为符合需求的buyer_id
效率不算高，但是简洁
```sql
SELECT S.buyer_id
FROM Sales AS S
JOIN Product AS P
ON S.product_id = P.product_id
AND P.product_name IN ('S8', 'iPhone')
GROUP BY S.buyer_id
HAVING COUNT(IF(P.product_name = 'iPhone', 1, NULL)) = 0;
```