### 方法一：多重子查询法 ###
#### 思路 ####
- 如果当前日期属于`2019`年且前一天（或后一天）不在所有`2019`年的记录中，则其为开始日期（或结束日期）
#### 代码 ####
```mysql []
select 'succeeded' period_state, start_date, min(end_date) end_date
from (
    select success_date start_date 
    from succeeded
    where year(success_date) = 2019 and date_sub(success_date, interval 1 day) not in (
        select success_date 
        from succeeded 
        where year(success_date) = 2019
    )
) s join (
    select success_date end_date 
    from succeeded
    where year(success_date) = 2019 and date_add(success_date, interval 1 day) not in (
        select success_date 
        from succeeded 
        where year(success_date) = 2019
    )
) e
on start_date <= end_date
group by start_date
union all
select 'failed' period_state, start_date, min(end_date) end_date
from (
    select fail_date start_date 
    from failed
    where year(fail_date) = 2019 and date_sub(fail_date, interval 1 day) not in (
        select fail_date
        from failed 
        where year(fail_date) = 2019
    )
) s join (
    select fail_date end_date 
    from failed
    where year(fail_date) = 2019 and date_add(fail_date, interval 1 day) not in (
        select fail_date
        from failed 
        where year(fail_date) = 2019
    )
) e
on start_date <= end_date
group by start_date
order by start_date
```

### 方法二：变量法 ###
#### 思路 ####
- 先将`succeeded`和`failed`表联合，提取出日期和状态
- 使用变量记录前一行的日期、前一行的状态以及当前区间的索引
- 如果当前行与前一行状态相同且日期间隔一天，则不更新索引，否则索引号加一
- 根据区间索引分组，并使用`min()`、`max()`得到开始日期和结束日期
#### 代码 ####
```mysql []
select state period_state, min(date) start_date, max(date) end_date
from (
    select 
        date, state,
        if(state = @prev_state and datediff(date, @prev_date) = 1, @i, @i := @i + 1) i, 
        @prev_date := date, @prev_state := state
    from (
        select success_date date, 'succeeded' state from succeeded
        union all
        select fail_date date, 'failed' state from failed
    ) tasks, (select @prev_date := '', @prev_state := '', @i := 0) vals
    where year(date) = 2019
) tmp
group by tmp.i
order by start_date
```
