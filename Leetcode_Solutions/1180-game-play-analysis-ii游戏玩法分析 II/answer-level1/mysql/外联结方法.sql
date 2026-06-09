将表自联结，on是player_id且所有日期小于主表的行。
如果附表为null，证明没有小于该行的日期，就是第一次登录的记录。
```
SELECT a1.player_id, a1.device_id
FROM activity a1 left join activity a2 on a1.player_id=a2.player_id and a1.event_date>a2.event_date
WHERE a2.event_date is NULL
```
