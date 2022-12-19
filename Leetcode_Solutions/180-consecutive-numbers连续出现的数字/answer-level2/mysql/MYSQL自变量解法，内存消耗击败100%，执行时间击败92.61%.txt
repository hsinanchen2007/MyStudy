### 解题思路
定义三个变量：@a,@pre,@pre2，
用@a记录num连续出现的次数，
@a = @a + (如果连续的num值一致则返回1，否则返回0) + (如果连续的num值 不 一致则返回1，否则返回0)*@a
通过@pre来对@a进行递增计数:(@pre = (@pre := Num))
通过@pre2来对@a清零:(@pre2 := Num))*@a   

### 代码

```mysql
# Write your MySQL query statement below
select DISTINCT Num as ConsecutiveNums from 
(select  Num,1+@a := @a + (@pre = (@pre := Num))-(@pre2 <> (@pre2 := Num))*@a as countit 
from Logs,(select @a := 1, @pre := -99999,@pre2 := -99999) t )k
where countit >= 3
```

