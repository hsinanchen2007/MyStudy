### 解题思路
先对Scores去重，然后逆序排序，同时排序的时候通过变量创建排序序号得到一个拥有Rank和Socre两个数据的表，命名为tA，然后让Scores表与tA进行inner join，可得到最终结果。但是有一个问题是通过select @rank：=0;的方法创建变量的时候。赋值结束后不是一个int类型的变量。不过在这个题目里可以通过。

### 代码

```mysql
# Write your MySQL query statement below
select Scores.Score,tA.Rank from(select (@rank:=@rank+1) Rank,Score from (select distinct Score from Scores)as A,(select @rank:=0) as Rank order by Score desc)as tA inner join Scores on Scores.Score=tA.Score order by Rank ;
```