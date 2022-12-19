### 解题思路
标记每个数字的起始位、末端位以及中位数所在位
再根据以上参数通过sum函数和嵌套if进行中位数运算，最后可得结果。

### 代码

```mysql
# Write your MySQL query statement below
select  sum(if((tem1.mid1>tem2.start and tem1.mid1<=tem2.end) and (tem1.mid2>tem2.start and tem1.mid2<=tem2.end),2*tem2.Number,
if((tem1.mid1>tem2.start and tem1.mid1<=tem2.end),tem2.Number,if((tem1.mid2>tem2.start and tem1.mid2<=tem2.end),tem2.Number,0)))/2) as median
from
(select n1.Number,@sums:=@sums+0 as start,@sums:=@sums+n1.Frequency as end from (select * from Numbers order by Number) as n1,(select @sums:=0) as s1) as tem2,
(select floor((sum(n2.Frequency)+1)/2) as mid1,floor((sum(n2.Frequency)+2)/2) as mid2 from Numbers as n2) as tem1
```