应用窗口函数技巧，可以比较快速的解题。

```sql
with tmp_act_ins as
	(select
		player_id,
		event_date,
		min(event_date) over(partition by player_id) as install_date
	from activity)
	
select
	to_char(install_date, 'yyyy-mm-dd') as "install_dt",
	count(distinct player_id) "installs",
	cast(
		sum(case when event_date = install_date + 1 then 1
				else 0
			end)
        /
        count(distinct player_id)
         as number(10, 2)) as "Day1_retention"
from tmp_act_ins
group by to_char(install_date, 'yyyy-mm-dd')
order by "install_dt"

```


但在运行时，leetcode 就是判我回答错误（见下图）。可我死活没看出来“输出“和”预期”的差异在哪。。
![2019-07-01_111953.png](https://pic.leetcode-cn.com/d65cfc7a175364284f78feae67796c1e103f329be1b2bf04d5ea4cbde087835a-2019-07-01_111953.png)
