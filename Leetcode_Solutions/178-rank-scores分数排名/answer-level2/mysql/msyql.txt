### 解题思路
1、先按分数降序排列 2、初始化两个变量，@score用来和源表score值逐行比对，@rank用来赋值排名 

### 代码

```mysql
# Write your MySQL query statement below
select a.score as "Score",cast(a.rn as signed) as "Rank"
  from (
        select a.score ,if(@score=a.score,@rank,@rank:=@rank + 1) as rn ,@score:=a.score
          from (select score from scores order by score desc) a,(select @score:=null,@rank:=0) b
        ) a
```