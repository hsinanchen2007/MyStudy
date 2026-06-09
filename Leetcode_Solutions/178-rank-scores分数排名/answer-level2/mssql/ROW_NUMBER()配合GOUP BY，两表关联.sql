### 解题思路
先排除Rank，以Group by 分组，Order by 排序。
接着解决排序序号的问题，用 ROW_NUMBER() 实现。

下一步，就是与原表关联，通过Score 来关联，得到结果

### 代码

```mssql
/* Write your T-SQL query statement below */

SELECT s.Score, r.[Rank]
FROM Scores s,
    (SELECT Score, ROW_NUMBER() OVER(ORDER BY Score DESC) [Rank]
    FROM Scores
    GROUP BY Score
    )  r 
WHERE s.Score = r.Score 
ORDER BY s.Score DESC
```