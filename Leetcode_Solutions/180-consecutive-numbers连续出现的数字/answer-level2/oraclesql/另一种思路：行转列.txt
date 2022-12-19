**如题所述**，
>行转列的思想，   缺陷：连续次数多了就GG了。
```
select 
   distinct tmp.num as ConsecutiveNums 
FROM (select 
         id
        ,lag(num) over (order by id ) as pre_num
        ,num
        ,lead(num) over (order by id) as next_num
    from Logs 
    ) tmp
where tmp.num=tmp.pre_num and  tmp.num=tmp.next_num`
```

**推荐另一种思路**：
>发现于题解，发布人：荆天明，主题：哈哈哈哈
他的核心思想是：利用统计__相同相对偏移量__的数量来达到要求
附上他的代码：
```
select distinct num ConsecutiveNums 
from ( select num, count(*) num_count 
		from ( select 
                              id,
                              num,
                              row_number() over (order by id) - row_number() over (partition by num order by id) x 
                          from logs )
		          group by num,x 
		          order by min(id); 
	) where num_count >=3

```