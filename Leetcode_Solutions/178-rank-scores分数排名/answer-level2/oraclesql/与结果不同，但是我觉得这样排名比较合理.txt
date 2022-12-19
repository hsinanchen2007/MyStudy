成绩排名的问题，我给我们学校做系统的时候，用的是下面的排名方式：
+-------|-------+-------+
|  名次 |  成绩	|  人数	|
+-------|-------+-------+
|	1	|	96	|	2	|
|	3	|	94	|	1	|
|	4	|	93	|	1	|
|	5	|	92	|	1	|
|	6	|	91	|	3	|
|	9	|	90	|	2	|
|	11	|	89	|	1	|
+-------|-------+-------+
我觉得这也是一种展示排名的方式，提供参考。

```
select score,rank,count(*) as cnt 
    from (select score,
        (select count(*)+1 from Scores a where a.score>b.score) as rank 
        from Scores b) c
    group by score,rank 
    order by score desc;
```
