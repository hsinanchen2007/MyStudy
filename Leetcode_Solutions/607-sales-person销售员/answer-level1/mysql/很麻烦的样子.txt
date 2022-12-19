### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select distinct a.name from orders b
right join salesperson a on a.sales_id=b.sales_id
left join company c on b.com_id=c.com_id 
where a.sales_id not in
(select a.sales_id from orders b
right join salesperson a on a.sales_id=b.sales_id
left join company c on b.com_id=c.com_id 
where c.name='red') or c.name is null
```