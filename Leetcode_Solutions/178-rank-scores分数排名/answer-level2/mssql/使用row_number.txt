select  Sr.Score,SS.Rank from Scores Sr
inner JOIN
(select Score,row_number() over (ORDER BY Score DESC) AS Rank FROM 
(select DISTINCT Score from Scores ) AS S) SS
ON Sr.Score=SS.Score ORDER BY Rank 