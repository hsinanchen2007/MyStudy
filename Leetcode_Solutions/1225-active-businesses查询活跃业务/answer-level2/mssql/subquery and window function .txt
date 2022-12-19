### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */
select business_id from 
(select e.business_id, 
case 
when occurences>temp.avg_count then 1
else 0
end as c_point from Events e
inner join 
(select business_id, event_type,
avg(cast(occurences as decimal(10,1))) over (partition by event_type) as avg_count from Events) temp
on e.business_id=temp.business_id and e.event_type=temp.event_type) temp_1
group by business_id having sum(c_point)>=2


```