
```
SELECT
	c.class 
FROM
	courses c 
GROUP BY
	c.class 
HAVING
	COUNT( DISTINCT c.student ) > 4;
```
为什么count的是student？
1.having 是处理的select查询处理的数据。
2.因为where条件后面的group by 的是class，所以这时候select查询到的class都只有一个（比如：Math=1，English=1...）
但是每个class对应的student的人数不是一个，Math的student的人数是5。

为什么要 DISTINCT ？
对student去重，是为了保证count的student的数量没有重复的数据。然后看看是不是 >= 5。我这里用的大于4。

