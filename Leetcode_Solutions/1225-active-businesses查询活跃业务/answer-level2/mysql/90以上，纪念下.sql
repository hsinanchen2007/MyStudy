### 解题思路
此处撰写解题思路
第一步 求出每个类型的平均发生次数
第二部 和events进行连接，对发生次数进行筛选，对业务分组，判断类型数是否大于2
### 代码

```mysql
# Write your MySQL query statement below

select p1.business_id
from Events p1 left join 
(select event_type,avg(occurences) as av
from Events
group by event_type) as p2
on p1.event_type =p2.event_type
where p1.occurences > p2.av
group by p1.business_id
having count(p1.event_type)>=2;


```