### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select table1.product_id,ifnull(table3.new_price,10) as price from products table1 left join
(select table1.* from products as table1 inner join
(select product_id,max(change_date) as change_date from products where change_date<='2019-08-16' group by product_id) as table2
on table1.product_id=table2.product_id 
where table1.change_date=table2.change_date) table3
on table1.product_id=table3.product_id
group by table1.product_id
order by table1.product_id asc





```