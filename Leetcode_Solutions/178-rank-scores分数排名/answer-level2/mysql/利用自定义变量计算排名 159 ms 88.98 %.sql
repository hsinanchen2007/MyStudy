```
SELECT Score, CAST(Rank AS signed) AS Rank
FROM (
  SELECT Score, @curr := IF(@prev = Score, @curr, @curr + 1) AS Rank, @prev := Score
  FROM Scores, (SELECT @curr := 0, @prev := null) t
  ORDER BY Score DESC
) temp
```
刚好看到自定义变量这块，自己摸索写了一下，感觉这个写法比较清晰。
用`prev`保存上一个分数的值，用`curr`保存当前排名，如果当前分数与`prev`一致，排名不变，否则`curr` + 1
每次再进行`prev` + 1的操作

不知道为啥算出来的Rank不是Integer，还要自己转一下。。
小白一枚，欢迎指正