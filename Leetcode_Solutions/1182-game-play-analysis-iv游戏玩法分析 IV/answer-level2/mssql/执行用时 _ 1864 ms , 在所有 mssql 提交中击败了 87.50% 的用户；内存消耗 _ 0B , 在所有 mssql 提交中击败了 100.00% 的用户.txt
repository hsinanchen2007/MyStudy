### 解题思路
1、查询出游玩超过1次的玩家数据
2、只取第二次和第一次游玩的日期间隔等于1天的
3、计算分数

### 代码

```mssql
/* Write your T-SQL query statement below */
select cast(count(distinct tt.player_id)*1.0/(select count(distinct player_id) cc from Activity) as decimal(38,2)) fraction from
(select t1.*,t2.event_date event_date2 from
(select * from (select *,row_number() over(partition by player_id order by event_date asc) rn from Activity) t where rn = 1) t1
left join
(select * from (select *,row_number() over(partition by player_id order by event_date asc) rn from Activity) t where rn = 2) t2
on (t1.player_id = t2.player_id and datediff(d,t1.event_date,t2.event_date) = 1)) tt
where event_date2 is not null
```