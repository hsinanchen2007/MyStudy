
【思路1】正确思路，较快
SELECT t.Score,t.Rank
FROM
(
SELECT  Score, 
if (@prevRank = Score,@curRank,@curRank := @curRank + 1)+0 AS Rank , @prevRank:=Score
FROM Scores p, 
(SELECT @curRank :=1, @prevRank := (SELECT max(Score) FROM Scores)) r
ORDER BY Score desc
) t

【思路2】一开始的错误思路，找不到错误的原因，当排序中Score出现零时，rank会返回null，没理解为何！！！求大佬指点迷津

SELECT Score,
CASE 
WHEN @prevRank = Score THEN @curRank 
WHEN @prevRank := Score THEN @curRank := @curRank + 1
END +0 AS Rank
FROM Scores p, 
(SELECT @curRank :=1, @prevRank := (SELECT max(Score) FROM Scores)) r
ORDER BY Score desc
