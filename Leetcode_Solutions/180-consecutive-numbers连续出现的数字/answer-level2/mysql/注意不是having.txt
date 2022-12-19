### 解题思路
此处撰写解题思路

### 代码

```mysql
select DISTINCT prd.num ConsecutiveNums from 
(
select  case when @num=a.num then @count:=@count+1
else @count:=0  end countnew,
case when @num=a.num then @num
else @num:=a.num  end numnew,
a.num
from logs a,(select @count:=0,@num:=null ) x  order by a.ID) prd 
where  prd.countnew>=2

```