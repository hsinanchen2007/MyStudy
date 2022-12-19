总结了题友们的答案：

解法一：
``` sql
select distinct t1.num as ConsecutiveNums 
from (select @x := @x + 1 as id, num
      from Logs, (select @x := 0) c1) t1,
     (select @y := @y + 1 as id, num
      from Logs, (select @y := 0) c2) t2,
     (select @z := @z + 1 as id, num
      from Logs, (select @z := 0) c3) t3
where t1.id = t2.id + 1
  and t2.id = t3.id + 1
  and t1.num = t2.num
  and t2.num = t3.num
```


解法二：
``` sql
select distinct t3.Num as ConsecutiveNums 
from (
    select Num,
        if(@a = Num, @b := @b + 1, @b := 1) as count,
        if(@b >= 3, 1, 0)                   as `rank`,
        @a := Num
    from Logs,
        (select @a := 0, @b := 0) t2) t3
where t3.`rank` = 1
```

如果还有更好的思路，请留言哦~ 蟹蟹
