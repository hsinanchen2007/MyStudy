数据库初学者的逆天思路
1.求和
```
SELECT seller_id,SUM(price) AS SUM
FROM sales
GROUP BY seller_id;
```
2.找最高值
```
SELECT MAX(SUM) FROM (
SELECT seller_id,SUM(price) AS SUM
FROM sales
GROUP BY seller_id) AS temp;
```
3.找最高值的id集合
```
SELECT * FROM (
SELECT seller_id,SUM(price) AS ma
FROM sales
GROUP BY seller_id) AS temp
HAVING ma =
(
	SELECT MAX(SUM) AS m FROM (
	SELECT seller_id,SUM(price) AS SUM
	FROM sales
	GROUP BY seller_id) AS temp2
)
```
4.从上面的集合中select出id
```
SELECT seller_id FROM (
	SELECT * FROM (
	SELECT seller_id,SUM(price) AS ma
	FROM sales
	GROUP BY seller_id) AS temp
	HAVING ma =
	(
		SELECT MAX(SUM) AS m FROM (
		SELECT seller_id,SUM(price) AS SUM
		FROM sales
		GROUP BY seller_id) AS temp2
	)
) AS temp3;
```
来大佬帮改进吧 T T
