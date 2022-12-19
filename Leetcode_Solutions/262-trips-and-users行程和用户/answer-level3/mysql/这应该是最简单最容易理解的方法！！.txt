执行用时 :360 ms, 在所有 MySQL 提交中击败了96.80%的用户
#1、内层计算每个日期No的总人数
#2、内层计算1中对应的complete人数
#3、内层1/2计算未取消的分数值，然后1-这个分数值，得到取消率
#4、由于内层日期不能人为指定，需要外层传入日期值
#5、在外层指定日期区间，因为内层指定了也没用（因为1-这个操作会导致日期区间失效）
```
select distinct b.Request_at as Day,Round(1-(select count(*)
from Trips a
where a.Client_Id not in(select Users_id from Users where Banned='Yes') and a.Driver_Id not in(select Users_id from Users where Banned='Yes') and a.Request_at=b.Request_at  and a.Status='completed')/(select count(*)
from Trips a
where a.Client_Id not in(select Users_id from Users where Banned='Yes') and a.Driver_Id not in(select Users_id from Users where Banned='Yes') and a.Request_at=b.Request_at),2) as 'Cancellation Rate'
from Trips b
where b.Request_at>= '2013-10-01' and  b.Request_at<='2013-10-03'
```
