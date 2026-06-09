### 解题思路
条件尽量在join条件中完成

### 代码

```mysql
# Write your MySQL query statement below

#事件类型在所有业务中的平均发生次数


select distinct business_id
from Events e
inner join (select event_type,avg(occurences) avg_occur
from Events
group by event_type) avg_o on e.event_type=avg_o.event_type and e.occurences>avg_o.avg_occur
group by business_id
having count(*)>1;

```