### 解题思路
SELECT 后面是要查找的列名，从两张表中查到，两张表通过PersonID来关联，题目中需要无论是否在Person表中有地址信息，都需要提供，这个时候只能通过左连接来将两张表连接起来。

### 代码

```mysql
# Write your MySQL query statement below
select FirstName,LastName,City,state
From Person a left join Address b on a.PersonID = b.PersonID;
```