### 解题思路
left join and right join. Can not get the result directly, so should think about "left join" and "right join".

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address a
on p.PersonId=a.PersonID;
```