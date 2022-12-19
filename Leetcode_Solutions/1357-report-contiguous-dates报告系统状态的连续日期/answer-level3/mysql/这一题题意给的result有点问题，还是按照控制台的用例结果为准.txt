我是这样想的：
  先按照日期递增的顺序把失败的和成功的天数连续查出来，sql如下：
 ```
    select date,period_state from (
	select fail_date as date,'failed' as period_state from failed
	where fail_date between '2019-01-01' and '2019-12-31'
	union all
	select success_date as date,'succeeded' as period_state from Succeeded
	where success_date between '2019-01-01' and '2019-12-31'
	) t1 order by t1.date as
```
然后按照连续天数的状态给个排名rank,连续的状态相同的rank一样，不一样的rank递增，
sql如下：
```
select date,period_state,
if(@prev = period_state ,@tmp := @tmp, @tmp := @tmp + 1) as rank,
@prev := period_state as prev from
(select date,period_state from (
	select fail_date as date,'failed' as period_state from failed
	where fail_date between '2019-01-01' and '2019-12-31'
	union all
	select success_date as date,'succeeded' as period_state from Succeeded
	where success_date between '2019-01-01' and '2019-12-31'
	) t1 order by t1.date asc) t2,(select @prev := null,@tmp := 0) as init
```

得到上述结果之后，再按照rank分组，把每一组的最大值和最小值分别作为start_date和end_date,
完整的sql如下:
```
select t3.period_state as period_state,min(date) as start_date,
max(date) as end_date from
(select date,period_state,
if(@prev = period_state ,@tmp := @tmp, @tmp := @tmp + 1) as rank,
@prev := period_state as prev
from
(select date,period_state from (
	select fail_date as date,'failed' as period_state from failed
	where fail_date between '2019-01-01' and '2019-12-31'
	union all
	select success_date as date,'succeeded' as period_state from Succeeded
	where success_date between '2019-01-01' and '2019-12-31'
	) t1 order by t1.date asc) t2,(select @prev := null,@tmp := 0) as init) t3
    group by rank
```
