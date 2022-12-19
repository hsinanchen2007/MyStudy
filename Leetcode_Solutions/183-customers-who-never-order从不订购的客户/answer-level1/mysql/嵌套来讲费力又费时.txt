### 解题思路
select name Customers from customers where name not in
(select a.name from customers a ,orders b 
where a.id=b.customerid)group by Customers 
感觉我非常愚蠢！上面的逻辑是错的


### 代码

```mysql
# Write your MySQL query statement below
select a.name Customers from customers a left join  orders b on a.id=b.customerid
where b.customerid is null
```