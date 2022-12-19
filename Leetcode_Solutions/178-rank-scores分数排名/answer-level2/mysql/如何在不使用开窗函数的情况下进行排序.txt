### 解题思路
此处撰写解题思路
1.Oracle中有排序的开窗函数：DENSE_rank(),rank()和row_number()，MySQL8.0中也有，如果不是用开窗函数，则需要生成**自增序列号**，进行join匹配
2.**如何生成自增序列号呢？**
2.1 使用变量，对应方法一，借鉴他人的方法
2.2 使用关联，**做出**序列号，对应方法二

### 代码

```mysql
# Write your MySQL query statement below
--方法一：使用系统变量生成
SELECT
    t1.Score,
    t2.rownum as Rank
from 
(
    SELECT
        Score 
    from 
        Scores 
    order by 
        Score desc
) t1 
left join
(    
SELECT
  @rownum:=@rownum+1 AS rownum,
  info.Score AS Score
FROM (SELECT
        @rownum:=0) r,
  (SELECT Score
   FROM Scores GROUP BY Score ORDER BY Score DESC ) info
) t2 
on 
    t1.Score = t2.Score

--方法二：
-- select 
--     t1.Score
--     ,Rank
-- from 
-- (
--     select 
--         Score
--     from 
--         Scores
--     order by 
--         Score desc
-- ) t1
-- left join
-- (
--     --此处为生成序列号
--     SELECT 
-- 	t1.Score AS Score
-- 	,COUNT(*) AS Rank
-- FROM 
-- (
-- 	SELECT 
-- 		Score
-- 	FROM 
-- 		Scores 
-- 	GROUP BY 
-- 		Score
-- 	ORDER BY 
-- 		Score DESC
-- ) t1,
-- (
-- 	SELECT 
-- 		Score
-- 	FROM 
-- 		Scores 
-- 	GROUP BY 
-- 		Score
-- 	ORDER BY 
-- 		Score DESC
-- ) t2 
-- WHERE t1.Score<=t2.Score
-- GROUP BY 
-- 	t1.score

-- ) t2 
-- on 
--     t1.Score = t2.Score

```
