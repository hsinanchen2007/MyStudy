通过排名算法实现,当前值`@n`和上一个值`@pre`比较,如果相等`@n+1` 否则`@n:=1`
最后在查询 count>=3的数据


```
代码块
select distinct  dd.Num ConsecutiveNums
from  (
select d.Num,
       @n :=if(@pre=Num,@n+1,@n:=1) count,
       @pre:=Num
from Logs d,
     (select @pre:=null, @n :=1)r)dd
where dd.count>=3;

```
