### 解题思路
我这里提供了两种思路，一种是使用左连接的子查询，还有一种是where后面的子查询，这两种方法效率都差不多，不高，不知道有没有大神有更高效的代码

### 代码

```mysql
/*select a.`Name` as Customers
from (select c.Id,c.`Name`,o.CustomerId
    from Customers c
    left join Orders o
    on c.Id=o.CustomerId) a
where a.CustomerId is  null;*/
select Name as Customers 
from Customers c 
where not exists ( select Name from Orders o where o.CustomerId = c.Id );
```