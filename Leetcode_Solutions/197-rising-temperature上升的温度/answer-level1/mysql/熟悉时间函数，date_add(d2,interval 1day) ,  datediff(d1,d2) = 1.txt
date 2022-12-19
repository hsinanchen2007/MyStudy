### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select w1.id  as id
from Weather w1 ,Weather w2
where w1.RecordDate = date_add(w2.RecordDate, interval 1 day)
and w1.Temperature >  w2.Temperature


-- select w1.id  as id
-- from Weather w1 ,Weather w2
-- where datediff(w1.RecordDate,w2.RecordDate) =1
-- and w1.Temperature >  w2.Temperature








```