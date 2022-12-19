### 解题思路
两个要求：
1. 时间差一天
2. 温度比昨天的高

求时间差：
1. Datediff(date1, date2)
2. Timediff(time1, time2)
3. date_add(date, interval 1 day/'01:15:30' hour_second/'1 01:15:30' day_second)
4. date_sub(date, intervel...)


### 代码

```mysql
# Write your MySQL query statement below
-- select w1.Id as Id
-- from Weather as w1
-- where w1.Temperature >
-- (
--     select w2.Temperature
--     from Weather as w2
--     where datediff(w1.RecordDate, w2.RecordDate) = 1
-- );

select w1.Id as Id
from Weather as w1, Weather as w2
where datediff(w1.RecordDate, w2.RecordDate) = 1 and w1.Temperature > w2.Temperature;
```