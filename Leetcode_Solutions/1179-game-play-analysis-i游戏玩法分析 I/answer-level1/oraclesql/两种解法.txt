
第一种就是min+group by 
```
select player_id,min(event_date) first_login
from activity
group by player_id;

```

第二种，考虑不确定的情况，即第N次登录的情况
```
select player_id,to_char(event_date) first_login
   from (
       select a.*,dense_rank() over(partition by player_id order by event_date) x
           from activity a ) tmp
	where tmp.x=N; 

```

