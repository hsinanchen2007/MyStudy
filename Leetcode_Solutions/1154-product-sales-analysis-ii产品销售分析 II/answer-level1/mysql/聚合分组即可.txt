### 解题思路


### 代码

```mysql
# Write your MySQL query statement below

select product_id,sum(quantity) total_quantity from sales
group by product_id

```