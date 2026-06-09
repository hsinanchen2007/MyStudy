
/*
#方法1：使用变量变量
#思路：变量+标记组别，获取连续可坐，不可坐区间，再筛选出可坐区间
select seat_id
from (select seat_id,free,case when free=@s then @gid else @gid:=@gid+1 end gid,@s:=free new_s
from (select * from cinema order by seat_id asc)t1,(select @gid:=0,@s:="")t2)t3
where gid in(
select gid
from
(select seat_id,free,case when free=@s2 then @gid2 else @gid2:=@gid2+1 end gid,@s2:=free new_s
from (select * from cinema order by seat_id asc)t4,(select @gid2:=0,@s2:="")t5)t6
group by gid
having count(*)>=2)
and free=1
order by seat_id asc
*/

#方法2 自连接  参考讨论区 id Sunny做法
select distinct c1.seat_id
from cinema c1,cinema c2
where abs(c1.seat_id-c2.seat_id)=1 and c1.free=1 and c2.free=1
order by seat_id asc