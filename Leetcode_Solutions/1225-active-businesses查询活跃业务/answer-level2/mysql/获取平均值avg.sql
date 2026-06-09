### 解题思路
只要首先获取到平均值大小就完事儿了
### 代码

```mysql
# Write your MySQL query statement below





select  business_id  from `Events` e1, (select 
event_type,
avg(occurences) as avgnums from `Events` group by event_type ) e2 where e1.event_type = e2.event_type and e1.occurences > e2.avgnums group by business_id having count(*) > 1
```