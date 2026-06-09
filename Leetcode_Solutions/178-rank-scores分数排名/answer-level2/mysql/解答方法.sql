### 解题思路
1：现将成绩分组排序  select Score from Scores group by Score order by Score Desc
2：增加序号 SELECT Score, (@i:=@i+1) Rank FROM ( select Score from Scores group by Score order by Score Desc
) as S,(select @i:=0)t
3：根据成绩联查序号，再根据序号排序 order By S2.Rank ASC;

### 代码

```mysql
# Write your MySQL query statement below
#方式一
#SELECT S1.Score,(select count(distinct(S2.Score)) from Scores as S2 where #S2.Score>=S1.Score ) as Rank  from Scores S1 order by Rank Asc;
#方式二
#select S1.Score,count(distinct(S2.Score)) as Rank from Scores as S1 , Scores as S2  #where 
#S1.Score<=S2.Score group by S1.Id order by Rank ASC;

select S1.Score,S2.Rank from Scores S1 left join (
 SELECT Score, (@i:=@i+1) Rank FROM ( select Score from Scores group by Score order by Score Desc
) as S,(select @i:=0)t 
) S2 on S1.Score=S2.Score order By S2.Rank ASC;


```