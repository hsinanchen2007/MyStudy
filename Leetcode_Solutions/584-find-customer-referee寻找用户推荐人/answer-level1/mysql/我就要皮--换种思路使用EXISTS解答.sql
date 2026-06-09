### 解题思路
该题可以用不等于解答，也可以使用not in 解答
我偏要用not EXISTS试试
相信以后在你需要的时候会用上EXISTS关键字

### 代码

```mysql
# Write your MySQL query statement below
select t.name from customer t where not EXISTS (
    select 1 from customer x where x.id=t.id and x.referee_id=2)

```