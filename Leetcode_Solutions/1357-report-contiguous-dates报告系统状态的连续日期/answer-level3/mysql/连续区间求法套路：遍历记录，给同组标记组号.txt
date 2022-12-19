# Write your MySQL query statement below
#思路：求连续区间，套路：利用变量给连续区间分配组号
#（1）union合并 并按照日期排序 t1
#（2）初始化组号变量gid，状态变量s 
#（3）遍历t1记录，并且case when 标记每行组号
#（4）按照组号分组统计，最小日期为起，最大为止
select state period_state,min(date) start_date,max(date) end_date 
from 
(select date,state,case when @s<>state then @gid:=@gid+1 else @gid end gid,@s:=state new_s
from 
(select * from
(select fail_date date,"failed" state from Failed where fail_date between "2019-01-01" and "2019-12-31"
union
select success_date date,"succeeded" state from Succeeded where success_date between "2019-01-01" and "2019-12-31")t1
order by date asc) t2,(select @s:="",@gid:=0) t3)t4
group by gid