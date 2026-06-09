### 解题思路
此处撰写解题思路
先算出每个业务的平均数，然后将器结果内联到原表中，where 选出大于平均的业务 having 出大于 符合where的个数
### 代码

```mysql
# Write your MySQL query statement below



select a.business_id 
from Events a inner join (
    select event_type, sum(occurences)/count(business_id) as avg_occur
    from Events
    group by event_type
)b
on a.event_type = b.event_type
where a.occurences > b.avg_occur
group by a.business_id 
having count(*) >=2

```