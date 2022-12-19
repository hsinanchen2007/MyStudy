### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select name Customers from Customers c left join orders o on c.id = o.CustomerId where o.CustomerId is null;
```
这是典型的左链接但不包含内连接的场景啊,A-(A∩B)