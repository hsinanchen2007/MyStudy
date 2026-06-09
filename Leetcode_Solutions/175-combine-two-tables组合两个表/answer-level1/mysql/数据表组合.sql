### 解题思路
使用左外连接的方式显示所有Person表中的信息及其关联的地址信息

### 代码

```mysql
# Write your MySQL query statement below
select FirstName, LastName, City, State from Person P left join Address A
    on P.PersonId = A.PersonId
```