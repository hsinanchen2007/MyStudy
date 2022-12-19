### 挤牙膏式解题
使用rank进行排序，定义两个变量r（用于表示rank值）、same（查看本次的score值是否等于上一次的score值），
当本次比较的score值等于same时，r不变，否则r + 1。

### 代码

```mysql
# Write your MySQL query statement below
-- select s.Score, if(@same = s.score, @r, @r := @r + 1) as Rank, @same := s.score from Scores as s,(select @r := 0, @same := null) as rt order by s.score desc; # v1.不符合答案要求,多出将score赋值给same这一列

-- select s.Score, (case when @same = s.score then @r when @same := s.score then @r := @r + 1 else null end) as Rank from Scores as s, (select @r := 0, @same := null) as rt order by s.score desc; # v2.Rank不是整数型而是string

-- select s.Score, cast((case when @same = s.score then @r when @same := s.score then @r := @r + 1 else null end) as unsigned integer) as Rank from Scores as s, (select @r := 0, @same := null) as rt order by s.score desc; # v3.这个不能解决null的问题

select s.Score, cast(
    ifNull(case 
    when @same = s.score then @r 
    when @same := s.score then @r := @r + 1 
    end, @r := @r + 1) as unsigned integer) as Rank 
    from Scores as s, (select @r := 0, @same := null) as rt order by s.score desc;
```