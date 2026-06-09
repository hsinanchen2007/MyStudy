### 解题思路
先去重找出下过订单的用户ID

### 代码

```mysql
# Write your MySQL query statement below
select Name  as Customers  from Customers where Id not in(select distinct CustomerId  from Orders )

```