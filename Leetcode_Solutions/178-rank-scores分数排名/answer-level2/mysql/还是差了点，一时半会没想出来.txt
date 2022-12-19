### 解题思路
count(distinct Score)  筛选出有几个等级

(select count(distinct Score) from Scores where Score >= s.Score)  查询比我大的前面的不重复的分数有多少个，那我就排在第几位

select Score,(select count(distinct Score) from Scores where Score >= s.Score) as Rank from Scores s order by s.Score desc  最后汇总在一起，倒序排列，得到最终结果

### 代码

```mysql
select Score,(select count(distinct Score) from Scores where Score >= s.Score) as Rank from Scores s order by s.Score desc
```


