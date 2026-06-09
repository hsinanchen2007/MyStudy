id不一定是顺序的，日期不一定是连续的。

用oracle的偏移分析函数lag，将前一天的记录放到一列里。

这个效率难道比两个表inner join，笛卡尔乘后在判断效率还低么? 用时2000ms。
```
select id
  from (select id,
               recorddate r2,
               Temperature as t2,
               lag(Temperature, 1, null) over(order by recorddate asc) as t1,
               lag(recorddate, 1, null) over(order by recorddate asc) as r1
          from Weather)
 where t1 is not null
   and t2 > t1
   and r2 - r1 = 1