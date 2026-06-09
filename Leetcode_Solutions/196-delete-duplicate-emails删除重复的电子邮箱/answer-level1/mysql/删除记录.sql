### 解题思路
删除记录时要注意：
删除和查询不能同时进行，会造成死锁。
可以把查询出来的结果当作一个临时表，然后从中选出想要的数据，再删除。

### 代码

```mysql
# Write your MySQL query statement below
delete from Person 
where Id not in
(select p1.Id 
from 
(select min(p2.Id) as Id 
from Person as p2 
group by p2.Email) as p1
);
```