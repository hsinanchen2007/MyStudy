

1. 自带的排名函数
```
# 要求mysql 版本 8.0+ ，所以leetcode 是不能提交的。
select score,dense_rank() over(order by score desc )  as Rank from scores
```

2.变量来实现排名 

首先初始化变量，在按照score 降序的过程中，逐步递增排名，相同分数的就不改变排名。
```
select score,cast(Rank as SIGNED) as Rank from (
select score,@r:=IF(@s=score,@r,@r+1) as Rank,@s:=score from scores a,(select @r:=0 ,@s:=null ) b order by score desc 
)as a 
```
