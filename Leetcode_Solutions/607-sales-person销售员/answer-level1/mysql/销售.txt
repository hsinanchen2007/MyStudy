### 解题思路
1. 将orders表与company表联结，找出所有销售给RED的销售id
2. 通过返回的销售id，从salesperson表中过滤掉这些员工

### 代码

```mysql
# Write your MySQL query statement below
SELECT name
FROM salesperson
WHERE salesperson.sales_id NOT IN
    (SELECT o.sales_id
    FROM orders o
    JOIN company c
    ON
    o.com_id = c.com_id AND c.name = 'RED');
        
```