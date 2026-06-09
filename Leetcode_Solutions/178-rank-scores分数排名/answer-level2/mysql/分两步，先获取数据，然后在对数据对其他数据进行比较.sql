### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


select a.Score ,(
    select 1+count(distinct b.Score) from Scores b where a.Score<b.Score
) as Rank
from Scores a
order by Score desc



```