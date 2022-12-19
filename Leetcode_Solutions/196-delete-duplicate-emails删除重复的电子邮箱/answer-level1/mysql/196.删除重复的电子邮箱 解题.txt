```
DELETE FROM Person  WHERE id NOT IN 
( SELECT * FROM ( SELECT MIN( id ) FROM Person GROUP BY Email ) t);
```
先分组查询最小的id，删除查询出的id以外的。
 
PS：当子查询查询结果是null时，not in 会有问题，可以用 not EXISTS。