### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT product_id,SUM(quantity) AS total_quantity 
FROM Sales GROUP BY product_id
```