### 解题思路
这里还是用变量来解题，只不过用了cast函数将Rank转化为整数。

### 代码

```mysql
# Write your MySQL query statement below
select Score,cast(Rank as signed) Rank
from (
select a.Score
    ,@rank:=if(@score=a.Score,@rank+0,@rank+1) as Rank
    ,@score:=a.Score
from Scores a 
join (select @rank:=0,@score:=null) b
order by a.Score desc
) c;
```

也可以用case when来做，就是不知道为何结果不通过：
```mysql
select a.*
    ,cast(case when @score = a.Score then @rownum := @rownum
    when @score := a.Score then @rownum:=@rownum+1
    else @rownum := @rownum
    end as signed) as Rank
from (
    select Score
    from Scores
    order by Score desc
) a,
(
    select @rownum:=0,@score:=0
) b;
```

不过这道题用变量显得复杂了，其他小伙伴的解题思路更好一些：

```mysql
select s1.Score,count(distinct(s2.score)) Rank
from
Scores s1,Scores s2
where
s1.score<=s2.score
group by s1.Id
order by Rank;
```
