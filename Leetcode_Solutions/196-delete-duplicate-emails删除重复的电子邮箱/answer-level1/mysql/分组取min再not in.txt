### 解题思路
(select min(Id) as id from Person group by Email) as temp)——按Email进行分组，选出每组Email的最小Id，此张表作为临时表temp
(select temp.id from 
((select min(Id) as id from Person group by Email) as temp))——从临时表temp中获得id，此时的id是邮箱的最小id
delete from Person 
where id not in 
(select temp.id from 
((select min(Id) as id from Person group by Email) as temp));——删除不在这些最小id里的id
**错误写法：delete from Person where id not in (select min(Id) as id from Person group by Email) as temp);！！！因为temp仅仅是一张表，需要从这张表再取出数据！！！**

### 代码

```mysql
# Write your MySQL query statement below
delete from Person 
where id not in 
(select temp.id from 
((select min(Id) as id from Person group by Email) as temp));


```