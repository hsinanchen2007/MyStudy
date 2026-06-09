### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select distinct  a.seat_id from
(select * from cinema where free >0) a
, (select * from cinema where free >0) b 
where a.seat_id  = b.seat_id-1 or a.seat_id  = b.seat_id+1
order by a.seat_id


```