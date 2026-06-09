### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below



select s1.gender ,s1.day,sum(s2.score_points) as total from Scores s1,Scores s2 where s1.gender  = s2.gender  and s1.day >= s2.day group by s1.gender ,s1.day
```