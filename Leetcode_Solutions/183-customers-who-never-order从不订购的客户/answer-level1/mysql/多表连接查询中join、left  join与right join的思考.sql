### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select a.Name AS Customers 
from Customers a
left join Orders b
on a.Id=b.CustomerId
Where b.CustomerId is null;
```
这道题目，让我从重新思考了left join 、right  join，inner join的示意图，以及加上where 。。is null之后的含义；
