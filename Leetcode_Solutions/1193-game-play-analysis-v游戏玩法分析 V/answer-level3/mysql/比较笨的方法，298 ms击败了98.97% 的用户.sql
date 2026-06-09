### 解题思路
一个表格计算留存率，一个表格统计注册数和注册日期

### 代码

```mysql

select install_dt, installs,round(ifnull(RETENT/installs,0),2) AS Day1_retention
FROM
    (
    SELECT install_dt,count(*) as installs 
    FROM
        (   select player_id,event_date,min(event_date) as install_dt 
            from activity  group by player_id) T2
    group BY install_dt
    ) P1
LEFT JOIN
    (
        SELECT date_add(event_date,interval -1 day) as Akey,count(*) as RETENT FROM
            (SELECT  player_id,date_add(min(event_date) ,interval 1 day)as second_date
            FROM activity group by player_id )t1, 
            Activity 
        WHERE T1.player_id = Activity.player_id AND T1.second_date = Activity.event_date
        group by event_date
    )P2
ON P1.install_dt = P2.Akey
```