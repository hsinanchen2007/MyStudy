### 解题思路
本题的思路很明显，子查询先使用group然后筛选出来哪些email是重复的，然后重复的email的最小id是什么。外部查询使用IN判断id在不在里面如果不再则删除即可。
```mysql
DELETE FROM Person where id not in (
    SELECT min(id) from Person group by email
);
```
但问题在于MySQL不支持删除子查询中的内容，子查询涉及到了Person表，所以外部查询中不允许删除该表中的内容，而且使用NOT IN也可能不走索引。

所以使用join实现删除子查询中的内容
```mysql
DELETE p FROM Person as p join(
    SELECT min(id)as id, email FROM Person group by email having count(id)>1
) as t 
ON p.id>t.id and t.email=p.email;
```