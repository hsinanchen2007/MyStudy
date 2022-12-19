/*
#方法1：
#思路：1 查询每个事件平均次数  2 筛选事件大于平均次数的记录 3 筛选高频事件大于2次的业务id
select business_id
from Events e,
(select event_type,sum(occurences)/count(event_type) avgoc 
from Events
group by event_type) t1
where e.event_type=t1.event_type
and e.occurences>t1.avgoc
group by business_id
having count(business_id)>=2

#方法2：标记后组内计算满足条件次数（运行超时:原因为遍历数据，并且每一次都要重新计算均值）
select business_id
from
(select *,case when e1.occurences>(select sum(e2.occurences)/count(1) 
from Events e2 where e2.event_type=e1.event_type) then 1 else 0 end tag
from Events e1)t1
group by business_id
having sum(tag)>=2
*/
#方法3：克服2缺陷
select business_id
from
(select e.*,avgoc
from Events e,
(select event_type,sum(occurences)/count(event_type) avgoc 
from Events
group by event_type) t1
where e.event_type=t1.event_type)t2
group by business_id
having sum(occurences>avgoc)>=2

