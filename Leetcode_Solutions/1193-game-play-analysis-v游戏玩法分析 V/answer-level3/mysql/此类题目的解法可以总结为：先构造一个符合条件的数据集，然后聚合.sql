首先找出所有玩家的第一次登陆时间：
```sql
select player_id,
       min(event_date) as install_dt
from Activity
group by player_id;
```

得到：
| player\_id | install\_dt |
| :--- | :--- |
| 1 | 2016-03-01 |
| 2 | 2017-06-25 |
| 3 | 2016-03-02 |

再和 Activity 关联，找出第二天登陆的玩家有那些

```sql
select t1.player_id, t1.install_dt, t2.player_id
from (
     select player_id,
            min(event_date) as install_dt
     from Activity
     group by player_id
) t1 left join Activity t2
    on t1.player_id = t2.player_id
        and t1.install_dt = date_sub(t2.event_date, interval 1 day);
```

得到：
| player\_id | install\_dt | player\_id |
| :--- | :--- | :--- |
| 1 | 2016-03-01 | 1 |
| 2 | 2017-06-25 | NULL |
| 3 | 2016-03-02 | NULL |

最后根据要求聚合即可
```sql
select install_dt,
       count(t1.player_id) as installs,
       round(count(t2.player_id) / count(t1.player_id), 2) as Day1_retention
from (
         select player_id,
                min(event_date) as install_dt
         from Activity
         group by player_id
     ) t1 left join Activity t2
         on t1.player_id = t2.player_id
            and t1.install_dt = date_sub(t2.event_date, interval 1 day)
group by 1
```

| install\_dt | installs | Day1\_retention |
| :--- | :--- | :--- |
| 2016-03-01 | 1 | 1.00 |
| 2016-03-02 | 1 | 0.00 |
| 2017-06-25 | 1 | 0.00 |

以上。