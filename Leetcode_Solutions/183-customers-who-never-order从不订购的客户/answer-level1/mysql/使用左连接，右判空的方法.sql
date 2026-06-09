### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
    t.name as Customers 
from 
    (select 
        c.name as name,o.id as id 
    from 
        Customers c left join Orders o 
    on 
        c.Id = o.CustomerId
    ) as t
where t.id is null

```
客户交易后肯定会在order表中出现，所有使用客户表进行左连接，订单表没有客户的id和客户id列为空，通过判空即可实现查找出为出现订单的名单。