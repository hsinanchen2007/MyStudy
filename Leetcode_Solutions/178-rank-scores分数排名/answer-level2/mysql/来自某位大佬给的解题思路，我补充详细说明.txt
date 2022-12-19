### 解题思路
此处撰写解题思路

### 代码

```mysql
select s1.Score,count(distinct(s2.score)) Rank
from
Scores s1,Scores s2
where
s1.score<=s2.score
group by s1.Id
order by Rank
```

想了几个小时，原来如此：
1. s1.score<=s2.score的意思是将满足这个条件的全部连接起来，默认是join连接，比如小于等于3.5条件的有6个。
所以id等于1和3.5的数据大概是这样的
执行一下sql语句是这样的
`select s1.id,s1.Score,s2.score
from
Scores s1,Scores s2
where
s1.score<=s2.score`

id s1.score s2.score
1   3.50      3.5
1   3.50      3.65
1   3.50      4.00  
1   3.50      3.85
1   3.50      4.00
1   3.50      3.65
2   3.65      3.65
2   3.65      4.00
后面自己补充，省略啦

2. group by s1.id 是对id进行分组，例如id等于1的就有6条记录，然后count()遇到group by后，是针对每一组进行分的，而不是对所有的数据进行统计。  id等于1的就有6条，  使用count(distinct(s2.score))去除重复的数据，因为4.00有2条，所以id等于1的有5条记录。排名就是第五啦。
3. order by 是最后执行的，作用是rank大小进行排序。