[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
先按player_id和event_date升序，再统计每个人的玩游戏的前缀和。

对于前缀和，用户变量解决更合适。

用户变量：pre_id——上一行的player_id，pre_date—— 上一行的event_date，sum_cnt——每个人games_played前缀和。
```
(SELECT @pre_id:=NULL,@pre_date:=NULL,@sum_cnt:=0) AS B
```
前缀和计算逻辑:
```
if (当前行的player_id = pre_id and 当前行的event_date != pre_date){
    sum_cnt = sum_cnt + 当前行的games_played
}else{
    sum_cnt = games_played
}
```
连接表Activity和表B：
```
SELECT 
	A.player_id,
	A.event_date,
@sum_cnt:= IF(A.player_id = @pre_id AND A.event_date != @pre_date,
			@sum_cnt + A.games_played,
			A.games_played 
		) AS `games_played_so_far`,
@pre_id:=A.player_id AS `player_ids`,
@pre_date:=A.event_date AS `event_dates`
FROM 
activity AS A,(
SELECT @pre_id:= NULL,@pre_date:= NULL,@sum_cnt:=0) AS B
ORDER BY A.player_id,A.event_date
```
但由于用户变量的限制，多出了两个字段player_ids，event_dates。

再投一次影，去掉多出的字段。
```
SELECT C.player_id,C.event_date,C.games_played_so_far
FROM (
SELECT 
	A.player_id,
	A.event_date,
@sum_cnt:=
		if(A.player_id = @pre_id AND A.event_date != @pre_date,
			@sum_cnt + A.games_played,
			A.games_played 
		)
		AS `games_played_so_far`,
@pre_id:=A.player_id AS `player_ids`,
@pre_date:=A.event_date AS `event_dates`

FROM 
activity AS A,(SELECT @pre_id:=NULL,@pre_date:=NULL,@sum_cnt:=0) AS B
order BY A.player_id,A.event_date
) AS C
```
# 解法二
将每个人，在日期A当天和之前，玩过的游戏个数累加。

同一个，在日期A当天和之前，用表自连接，group by，找出这些行。也是这类累加和或前缀和问题的通用解法。
```
SELECT *
FROM Activity AS A JOIN Activity AS B ON (A.player_id = B.player_id AND A.event_date <= B.event_date)
```
补上group by及组内求和。
```
SELECT B.player_id,B.event_date,SUM(A.games_played) AS `games_played_so_far`
FROM Activity AS A JOIN Activity AS B 
ON (A.player_id = B.player_id AND A.event_date <= B.event_date)
GROUP BY B.player_id,B.event_date
```

