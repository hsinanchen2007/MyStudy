### 解题思路
代码自己看，思想简单，不好实现，用了多层嵌套查询。执行时间149ms，超过76%用户，消耗内存0 MB，超过100%用户

### 代码

```mysql
SELECT b.id,b.visit_date,b.people
FROM
	(SELECT id,visit_date,people,IF(people>=100,@groups:=@i,@groups:=0) AS ranking,IF(people<100,@i:=@i+1,@i:=@i) AS temp
	 FROM stadium
	 CROSS JOIN (SELECT @groups:=0,@i:=1) AS a
	) AS b
WHERE 
	b.ranking IN 
	(SELECT e.ranking1
	 FROM
		(SELECT ranking1,COUNT(*) AS num
		 FROM
			(SELECT IF(people>=100,@groups1:=@i1,@groups1:=0) AS ranking1,IF(people<100,@i1:=@i1+1,@i1:=@i1) AS temp1
			FROM stadium
			CROSS JOIN (SELECT @groups1:=0,@i1:=1) AS c
			)AS d
		 WHERE d.ranking1>0
		 GROUP BY d.ranking1
		 ) e
	WHERE e.num>=3
	)
order by id;

```