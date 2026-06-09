### 解题思路
此处撰写解题思路
257ms
### 代码

```mysql
# Write your MySQL query statement below
select p.Firstname as FirstName,p.lastname as LastName,a.city as City,a.state as State from address a right join person p 
on p.personid = a.personid
```