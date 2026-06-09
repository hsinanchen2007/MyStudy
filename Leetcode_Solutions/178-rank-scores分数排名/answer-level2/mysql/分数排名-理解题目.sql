### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select S1.Score,COUNT(DISTINCT(S2.Score)) Rank
from Scores S1, Scores S2
where S1.Score <=S2.Score
group by S1.Id
order by Rank;
```
这道题目，一开始想到的是使用开窗函数
rank（）/dense_rank()/row_number()  over (order by 成绩 desc)
其中要理解rank（）、dense_rank（）/row_number() 之间的区别
假设数据为
ID    成绩
1     10
2     10
3     12
4     13

使用rank（）的结果是
成绩   排名
10     1
10     1
12     3
13     4

使用dence_rank的结果是
成绩   排名
10     1
10     1
12     2
13     3

使用row_number的结果是
成绩   排名
10     1
10     2
12     3
13     4

但是在执行的时候，我写的
select Score,dense_rank() over(order by Score desc) Rank
from Scores;
会出现错，看了其他的文章可能是执行版本的问题；

所以换了一种思路，使用自查询的方式
使用group by 与order by 做分组排序 按照id作为分组，排名作为排序
使用where做条件语句，
count（）聚合函数计算当个成绩的个数