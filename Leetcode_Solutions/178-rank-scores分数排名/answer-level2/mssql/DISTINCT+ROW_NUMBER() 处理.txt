SELECT b.Score AS Score,b.Rank FROM Scores INNER JOIN (
SELECT Score,ROW_NUMBER() OVER (ORDER BY Score DESC) AS Rank FROM (
SELECT DISTINCT(Score) AS Score FROM Scores)a)b ON b.Score = Scores.Score
ORDER BY b.Rank