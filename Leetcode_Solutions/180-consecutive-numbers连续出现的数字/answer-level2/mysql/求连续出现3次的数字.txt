### 解题思路
还有一种方法是用窗口函数，但在这里执行不了，在MYSQL8可以执行~
思路：a表按照Num 来分组并在组内按Id排序，得到排序编号； b表，用Id减去排序编号，如果是连续排序，则结果相同，否则不一样；c表，根据Num和Id减去排序编号的结果，计数
select Num as  ConsecutiveNums 
from
(
select b.Num,b.结果,count(*)
from
(
select *,a.Id-a.ranking as 结果
from 
(
select *,row_number() over (partition by Num order by Id) as ranking
from Logs
)a
)b
group by b.Num,b.结果
having count(*) >=3
)c;


### 代码
自联结
```mysql
select distinct(t.Num1) as  ConsecutiveNums
from
(
select L1.Id
      ,L1.Num as Num1
      ,L2.Num as Num2
	  ,L3.Num as Num3
from Logs as L1
inner join Logs as L2
on L1.Id = L2.Id + 1
inner join Logs as L3
on L1.Id = L3.Id + 2
order by L1.Id
)t
where Num1 = Num2
   and Num1 = Num3;

```