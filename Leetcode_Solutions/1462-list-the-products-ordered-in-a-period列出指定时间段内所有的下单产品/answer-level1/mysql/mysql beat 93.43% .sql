### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


select product_name,total_sum as unit from Products p 
inner join 
(select product_id, sum(unit) as total_sum from Orders 
where order_date between '2020-02-01' and '2020-02-29'
group by product_id) temp
on temp.product_id=p.product_id
where total_sum>=100

```