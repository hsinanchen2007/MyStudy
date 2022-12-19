### 解题思路
此处撰写解题思路
左连接求当前累计重量，求出最后一个接近1000的人
### 代码

```mysql
# Write your MySQL query statement below

select res.person_name
from  Queue res
where res.turn in (
    select t.turn 
    from(    
        select max(q2.turn) as turn
        from Queue q1 left outer join Queue q2
        on q1.turn>=q2.turn
        group by q1.turn
        having sum(q2.weight) <=1000
        order by q1.turn desc
        limit 1)t
)
```