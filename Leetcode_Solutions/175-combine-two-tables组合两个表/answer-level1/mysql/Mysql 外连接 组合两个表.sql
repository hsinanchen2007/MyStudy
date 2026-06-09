### 解题思路
将address表左连接入person表中


### 代码

```mysql
# Write your MySQL query statement below
select FirstName, LastName, City, State from person left join address on person.personid=address.personid
```