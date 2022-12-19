### 解题思路
1. 初始和遇到有人的座位都为变量置0
2. 如果当前座位和前面都空着则变量自增,添加这个座位
3. 若当前座位空但前面有人,需要判断下个座位是否有人或没有了
绞尽脑汁仍然想不到如何添加末尾id,即多追加一个有人的座位,为长度+1
做in搜索的时候是否搜索一次就查询一次? 由于找有人的座位是固定的如果能缓存起来就好了
座位有人时,为什么不能设置变量为0,非常奇怪

### 代码

```mysql
# Write your MySQL query statement below

-- select distinct a.seat_id
-- from cinema as a
-- inner join cinema as b
-- on a.free = 1 and (b.seat_id in(a.seat_id-1 ,a.seat_id+1) and b.free = 1)


select distinct seat_id
from cinema
inner join (select @n := 0,(select count(*) from cinema) as c) as t
on case 
    when free = 0 then @n := @n-@n # 为什么不能等于0
    when free = 1 and @n>0 then @n := @n+1
    else @n := seat_id+1 not in(select seat_id from cinema where free=0) and seat_id < t.c
    end

```