## 思路

1. 分析本题，让求出首次登陆游戏后第二天又登陆游戏的玩家所占的比例，保留两位小数；

2. 首先我们可以把问题拆分，先求出所有玩家第一次登陆的数据，然后把这个作为临时表，然后我们把所有数据和他们第一次登陆的数据进行比较，如果日期相差1天，即为符合条件的玩家，用这部分的玩家数量除以所有玩家的数量，然后保留两位小数就可以得出结果了；

3. 解法有多种，但是思路都是一样的，选择最直观效率的方法完成即可

## 结论

1. 求出所有玩家首次登陆数据

    ```sql
    select player_id,min(event_date) first_date from activity group by player_id
    ```

2. 将所有玩家首次登陆数据作为临时表，并和所有数据表activity进行关联

    ```sql
    select *
    from activity a,
    (select player_id,min(event_date) first_date from activity group by player_id) b
    where a.player_id=b.player_id
    ```

3. 使用datediff函数计算玩家每次登陆和首次登陆的日期差，使用count+distinct函数获取所有玩家数

    ```sql
    select datediff(a.event_date,b.first_date),(select count(distinct(player_id)) from activity)
    from activity a,
    (select player_id,min(event_date) first_date from activity group by player_id) b
    where a.player_id=b.player_id
    ```

4. 使用case when then else过滤出所有符合条件的玩家，然后使用sum求和，计算出符合条件的玩家数目

    ```sql
    select sum(case when datediff(a.event_date,b.first_date)=1 then 1 else 0 end),(select count(distinct(player_id)) from activity)
    from activity a,
    (select player_id,min(event_date) first_date from activity group by player_id) b
    where a.player_id=b.player_id
    ```

5. 最后将符合条件的玩家数除以所有玩家数，并使用round函数，保留两位小数,并且按照例子上面的输出结果给列名取个别名即可
    ```sql
    select round(sum(case when datediff(a.event_date,b.first_date)=1 then 1 else 0 end)/(select count(distinct(player_id)) from activity),2) as fraction
    from activity a,
    (select player_id,min(event_date) first_date from activity group by player_id) b
    where a.player_id=b.player_id
    ```

***

## 结果

```sql
select round(sum(case when datediff(a.event_date,b.first_date)=1 then 1 else 0 end)/(select count(distinct(player_id)) from activity),2) as fraction
from activity a,
(select player_id,min(event_date) first_date from activity group by player_id) b
where a.player_id=b.player_id
```