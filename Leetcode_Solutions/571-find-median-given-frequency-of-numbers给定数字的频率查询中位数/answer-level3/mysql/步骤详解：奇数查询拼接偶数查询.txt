**思路：** 拆分成已知总数为奇数、偶数的求中位数的两条语句，并通过子查询的方式并入一条带if的查询语句中即可。
**第一步** 获取累计数表。通过自连接，获取每个数Frequency的累加值num。
(*注意这里between中的(select max(Number) from Numbers)条件，决定了每个a的数字下的b.Frequency记录的数量，以应对样例中数字为0~999的情况。*)
```
select a.Number,sum(b.Frequency) as num from Numbers a,Numbers b 
where (a.Number-b.Number) between 0 and (select max(Number) from Numbers) group by a.Number
```
**第二步** 奇数情况。由于是奇数，单条件匹配取第一个记录即可。
```
select Number
from (第一步代码) c
where num>(select sum(Frequency)/2 from Numbers)
limit 1
```
**第三步** 偶数情况。这里的if作为第二条件筛选。由于数据严格按照01234的顺序和+1递增规则，因此中位数只可能是x或者x+0.5 *即(x+x)/2=x，(x+x+1)/2=x+0.5*
```
select if(num-1>=(select sum(Frequency)/2 from Numbers),Number,Number+0.5) as number
from (第一步代码) c
where num>=(select sum(Frequency)/2 from Numbers)
limit 1
```
**第三步** 整合上述结果，结构如下：
`select if(sum(Frequency)%2=0,偶数情况，奇数情况） from Numbers`
完整代码：
```
select if(sum(Frequency)%2=0,
    (select if(num-1>=(select sum(Frequency)/2 from Numbers),Number,Number+0.5) as number
    from (select a.Number,sum(b.Frequency) as num from Numbers a,Numbers b 
    where (a.Number-b.Number) between 0 and 3 group by a.Number) c
    where num>=(select sum(Frequency)/2 from Numbers)
    limit 1),
    (select Number
    from (select a.Number,sum(b.Frequency) as num from Numbers a,Numbers b 
    where (a.Number-b.Number) between 0 and (select max(Number) from Numbers) 
    group by a.Number) c
    where num>(select sum(Frequency)/2 from Numbers)
    limit 1)
) as median from Numbers
```
