### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select C.Name as Customers
from Customers C 
where C.Id not in (
    select O.CustomerId
    from Orders as O
)
```