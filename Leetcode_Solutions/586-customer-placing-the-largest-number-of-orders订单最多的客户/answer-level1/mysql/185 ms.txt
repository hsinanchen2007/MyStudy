### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select customer_number from
(SELECT customer_number,count(customer_number) as num FROM orders
group by customer_number)t
order by num desc limit 0,1
```