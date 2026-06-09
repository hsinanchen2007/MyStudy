**请编写一个 SQL 查询，描述每一个玩家首次登陆的设备名称**
看到这个题的时候就会想到,想要查询的首次登陆的设备名称,我们可以查询出最早登陆的日期,通过最早的登陆日期来查询设备名称和PLAYER_ID,

```
select a.player_id ap,MIN(a.event_date) ed from Activity a group by a.player_id
```
这样我就得到了最早的登陆的日期,接下来就可以通过连接表的方式来查询数据,(这里因为查出来的数据也是可以看成一个表的嘛)

```
select  ac.player_id,ac.device_id from Activity ac left join (
    select a.player_id ap,MIN(a.event_date) ed from Activity a group by a.player_id
) as bj on ac.event_date = bj.ed where ac.player_id = bj.ap;
```
这里的条件也就是要查询的日期等于最早的日期,然后还要过滤下playerplayer_id就好了