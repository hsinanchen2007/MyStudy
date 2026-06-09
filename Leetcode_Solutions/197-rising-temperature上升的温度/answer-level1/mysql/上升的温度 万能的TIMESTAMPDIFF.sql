TIMESTAMPDIFF能干什么，可以计算相差天数、小时、分钟和秒，相比于datediff函数要灵活很多。格式是时间小的前，时间大的放在后面。
计算相差天数：
```
select TIMESTAMPDIFF(DAY,'2019-05-20', '2019-05-21'); # 1
```
计算相差小时数：
```
select TIMESTAMPDIFF(HOUR, '2015-03-22 07:00:00', '2015-03-22 18:00:00'); # 11
```
计算相差秒数：
```
select TIMESTAMPDIFF(SECOND, '2015-03-22 07:00:00', '2015-03-22 7:01:01'); # 61
```
采用联结表的方式，条件是：1）与之前的日期相差为 1天，2）当天温度比之前一天的温度高
```
select w1.Id
from Weather as w1, Weather as w2
where TIMESTAMPDIFF(DAY, w2.RecordDate, w1.RecordDate) = 1 AND w1.Temperature > w2.Temperature
```
