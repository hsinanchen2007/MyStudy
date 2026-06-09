### 解题思路
1、设置两个变量，一个变量用于记录上一个数字，一个变量用于记录当前数字出现的次数。
2、在Mysql中，数字0对应false，大于1的数字对应true，因此if(@preNum=Num,@viewTimes:=@viewTimes+1,@viewTimes:=1)-1就能够判断出当前数字与上一个数字是否重复。如果重复，那么当前数字至少出现了两次，在继续到then中去判断。如果当前数字不与上一个数字重复，那么就给记录上一个数字的变量赋值当前数字（“when @preNum:=Num”的作用是先对@preNum进行赋值，赋值后再进行when的条件判断，大于0的数字都是true哟）。
3、最后将出现次数大于等于3的重复数字distinct掉，然后过滤掉为null的输出就ok啦
    


### 代码

```mysql
select distinct ConsecutiveNums  from 
(
select case
when if(@preNum=Num,@viewTimes:=@viewTimes+1,@viewTimes:=1)-1 then if(@viewTimes>=3,Num,null)
when @preNum:=Num then null
end as ConsecutiveNums
from Logs a,(select @preNum:=null,@viewTimes:=0)b
) a where ConsecutiveNums is not null

```