
### 代码

```mysql
# Write your MySQL query statement below
select a.Name as Customers 
from(
    select Name,CustomerId 
    from Customers 
    left join Orders 
    on Customers.Id = Orders.CustomerId
    ) a
where a.CustomerId is NULL
```