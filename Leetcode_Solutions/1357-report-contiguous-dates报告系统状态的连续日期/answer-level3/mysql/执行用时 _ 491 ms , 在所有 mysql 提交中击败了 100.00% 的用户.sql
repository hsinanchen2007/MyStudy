这道题就是求连续日期，首先将满足日期要求的失败和成功记录组合起来，在这个过程中给连续的日期一个用于今后分组的标记，接下来按标记进行分组就可以了，我的答案如下：
select status as period_state, min(date) as start_date, max(date) as end_date
from
(select * from (select fail_date as date, 'failed' as status, if(datediff(@pre, @pre := fail_date) = -1, @a, @a := @a + 1) as groupmark from Failed, (select @a := 0, @pre := "2018-07-07") as temp
union
select success_date as date, 'succeeded' as status, if(datediff(@cur, @cur := success_date) = -1, @b, @b := @b + 1) as groupmark from Succeeded, (select @b := 100, @cur := "2018-07-07") as temp
               ) as temp where date between "2019-01-01" and "2019-12-31"
order by date) as s
group by groupmark
order by min(date);