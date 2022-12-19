### 解题思路
就1句代码搞定

### 代码

```mysql
# Write your MySQL query statement below

select Name Customers from Customers where Id not in (select CustomerId from Orders)


```