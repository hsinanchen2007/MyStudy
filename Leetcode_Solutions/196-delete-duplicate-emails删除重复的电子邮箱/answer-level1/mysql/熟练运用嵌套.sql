### 解题思路
此处撰写解题思路

### 代码

```mysql
delete from Person where id in (select id from
(select p1.Id from Person as p1,Person as p2
where p1.Email = p2.Email
and p1.Id > p2.Id
) as temp)

```