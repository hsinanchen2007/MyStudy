### 解题思路
首先获取分组获取每个分数段的分数和排名作为临时表
利用@i:=@i+1获取分数段编号
然后以原表作为主表，左关联临时表
不要忘记转整形CONVERT(bx.Rank,SIGNED) as Rank

### 代码

```mysql
# Write your MySQL query statement below
#select Score,count(*) from Scores group by Score order by count('Score') desc
-- SET @i := 0;






SELECT ax.Score,CONVERT(bx.Rank,SIGNED) as Rank from Scores as ax LEFT JOIN 
(SELECT Score,(@i:=@i+1) Rank from (SELECT @i:=0) r,
(SELECT
		Score
	FROM
		Scores
	GROUP BY
		Score
	ORDER BY
		Score DESC) as a) as bx on ax.Score=bx.Score ORDER BY ax.Score desc;
```