1. 其实首先考虑的是，使用游标和临时表来实现

```
DECLARE @curNum int,@lastNum int, @curCount int
IF OBJECT_ID('tempdb..#result') IS NOT NULL
    DROP TABLE #result
CREATE TABLE #result(ConsecutiveNums int)

DECLARE logs_cursor CURSOR FOR
SELECT Num FROM Logs

OPEN logs_cursor
FETCH NEXT FROM logs_cursor
INTO @lastNum

SELECT @curNum=@lastNum, @curCount=0

WHILE @@FETCH_STATUS = 0
BEGIN
    IF @curNum=@lastNum
    BEGIN
        SET @curCount=@curCount+1
    END
    ELSE
    BEGIN
        IF @curCount>=3
        BEGIN
            INSERT #result VALUES(@curNum)
        END
        SELECT @curNum=@lastNum, @curCount=0
    END

    FETCH NEXT FROM logs_cursor
    INTO @lastNum
END

CLOSE logs_cursor;  
DEALLOCATE logs_cursor; 

SELECT ConsecutiveNums FROM #result
```
*执行错误（本地可以正常运行，因为没有具体错误信息，此方案废弃）*


2. 考虑过使用WITH做递归，一直查找下一个Id；Num相等则累计，不同则从1重新开始

```
WITH logs_cte(lastId, curId, Num, NumCount) AS
(
    SELECT TOP 1 Id, Id+1, Num, 1 FROM Logs
    UNION ALL
    SELECT l.Id, l.Id+1, l.Num, (CASE 
		WHEN l.Num=c.Num THEN c.NumCount+1
		ELSE 1 END) FROM Logs l
    INNER JOIN logs_cte c ON l.Id=c.curId
)
SELECT Num ConsecutiveNums  FROM logs_cte
WHERE NumCount=3
```
*部分用例错误：Logs记录在100以内没问题，超过100，会由于SQL嵌套层数超过100而报错*


3. 考虑在列上使用内部查询，Num不同，取nextId的MIN值与curId相减得到count
需注意界限值的问题

```
DECLARE @maxId int
SELECT @maxId=MAX(Id) FROM Logs

SELECT DISTINCT Num ConsecutiveNums
FROM
(SELECT curl.Id, curl.Num, ISNULL((SELECT MIN(Id) 
	FROM Logs
	WHERE Num<>curl.Num
	AND Id>=curl.Id), @maxId+1)-Id c 
FROM Logs curl) t
WHERE c=3
```
*部分用例错误：Id不连续的情况，count有误*


最好，修改例3的Id为Row_Number来实现，完成解答
