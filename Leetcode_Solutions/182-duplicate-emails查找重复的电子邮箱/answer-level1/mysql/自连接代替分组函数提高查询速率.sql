### 解题思路
利用Id列做自连接查询，这个用时确实要比group by快不少。

### 代码

```mysql
# Write your MySQL query statement below
select distinct a.Email 
from Person a, Person b 
where a.Email = b.Email and a.Id != b.Id
```

```mysql
select Email
from Person 
group by Email
having count(Email)>1;
```