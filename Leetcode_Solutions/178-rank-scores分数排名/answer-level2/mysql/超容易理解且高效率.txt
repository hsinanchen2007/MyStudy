容易理解的语句，且效率高于99%
首先根据任务进行分析，目的进行连续的并列排序，并且以整型的字段返回。
语句执行顺序为 from  -> select -> oder by(这是每个查询执行的顺序，子查询也一样)
对分数进行判断，相同即排名不变，不相同排名加一。使用if语句进行判断，ex:if(a>1,A,B) 如果为真返回A，反之返回B
SELECT Score, Rank FROM
(SELECT Score,
@curRank := IF(@prevRank = Score, @curRank+0,@curRank:=@curRank+1) AS Rank, 
@prevRank := Score
FROM Scores, (
SELECT @curRank :=0, @prevRank := NULL
) r 
ORDER BY Score DESC) s