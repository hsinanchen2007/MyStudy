SELECT T.Score,T.Rank FROM
(SELECT @ROWNUM:=@ROWNUM + 1 Rank, Score 
    FROM (SELECT @ROWNUM:=0) R,
        (SELECT DISTINCT Score FROM Scores ORDER BY Score DESC) E
) T
LEFT JOIN Scores EM
ON T.Score = EM.Score
ORDER BY T.Rank