### 解题思路
啊这,有重名咋不说清楚呢?

### 代码

```mssql
/* Write your T-SQL query statement below */
select Name as Customers from Customers
where Id not in(
select Customers.Id from Orders,Customers
where Orders.CustomerId=Customers.Id)
```