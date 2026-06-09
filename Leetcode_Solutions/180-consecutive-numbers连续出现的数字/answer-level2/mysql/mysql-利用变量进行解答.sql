
```
select distinct num as ConsecutiveNums  from (
select num,
if(@num1=num,@num:=@num+1,@num:=1) as ConsecutiveNums1,
@num1:=num,
if(@num>=3,1,0) as rank1
from logs t1,
(select @num:=0,@num1:=null) t2) t3 where rank1=1
```
# 核心思路
利用变量进行标注，当数字连续出现三次以上时标注为1，其余情况都标注为0！
> 最后只要对结果去重就可以满足题目需求！