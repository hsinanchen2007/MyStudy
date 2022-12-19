### 解题思路
1.运用(+)，等同left join，看起来更简洁。
2.副表值为null的，即符合题目要求，输出。

### 代码

```oraclesql
/* Write your PL/SQL query statement below */

 select c.Name as Customers
   from Customers c, Orders o
  where c.id = o.CustomerId(+)
    and o.CustomerId is null
```