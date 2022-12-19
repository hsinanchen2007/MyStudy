添加一列序号。
```
SELECT 
    s.Score AS Score, @num:=@num+1 AS Rank
FROM 
    (SELECT DISTINCT Score FROM Scores ORDER BY Score DESC) s, (SELECT @num:=0) r
```
得到去重后的 Score 和 Rank。
外连接此条查询，得到如下 SQL,两表的 Score 作为关联关系,a 表的 Score 与 b 表的 Score 相等时 Rank相同。 
```
SELECT a.Score, p.Rank
FROM Scores a 
    LEFT JOIN
        (
            SELECT s.Score AS Score, @num:=@num+1 AS Rank
            FROM (SELECT DISTINCT Score FROM Scores ORDER BY Score DESC) s, (SELECT @num:=0) r
        ) AS p
    ON a.Score = p.Score
ORDER BY a.Score DESC
```