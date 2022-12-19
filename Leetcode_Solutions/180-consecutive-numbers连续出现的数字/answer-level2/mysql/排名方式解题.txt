### 解题思路
通过id的顺序排名，保留上次的num 来判断 当前排名是否需要改变，
在通过相同的排名来分组，having count(*)>=3 筛选， distinct 去重即可。

### 代码

```mysql
# Write your MySQL query statement below

select distinct max(Num) ConsecutiveNums from (
    select Num ,@r:=IF(@n=Num,@r,@r+1) as rr,@n:=Num from logs a,(select @r:=0,@n:=null) b Order by Id asc
) as a  group by a.rr having count(*)>=3 
```