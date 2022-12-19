### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select Name as 'Customers' from Customers where Id not in (select o.CustomerId from Orders as o left join Customers as c on o.CustomerId = c.Id);
```