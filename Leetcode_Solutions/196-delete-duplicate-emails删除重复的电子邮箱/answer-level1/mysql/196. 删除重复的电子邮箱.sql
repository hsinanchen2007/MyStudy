答案：
DELETE p3
FROM Person p3 
WHERE p3.id IN(select pp.id from (select p.id from  Person p, Person p2 where p.email=p2.email and p.id > p2.id) pp )

思路：
把所有重复email并且id大的所有id找出来一一删除

踩过的坑：
一开始写的时候是这样
    DELETE p2
    FROM Person p2 
    WHERE p2.id IN(select p.id from  Person p where p.email=p2.email and p.id > p2.id)
结果给你来个‘You can't specify target table 'xxx' for update in FROM clause’的错误
大致意思是，在同一语句中，不能先select出同一表中的某些值，再update这个表。
因此在查询的时候增加一层中间表避免该错误。