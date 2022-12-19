#思路：通过自定义变量不进行order 排序，相同的数值只有是连续的两个值得排名才会一致，再进行group分组，得到数量大于三的数据
```
select distinct t.num  as ConsecutiveNums from (
    select 
        Num,
        @num := @num + (@pre <> @pre :=Num) as ok
    from Logs l ,
    (select @num :=0,@pre:=-1) b
 )t group by ok having  count(ok) >=3;
```
