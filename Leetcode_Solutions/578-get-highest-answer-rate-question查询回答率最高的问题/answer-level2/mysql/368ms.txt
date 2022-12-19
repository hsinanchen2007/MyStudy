### 解题思路
这道题大部分时间在理解题意上了，q_num其实一点用没用，瞎写尝试才对的。
评论区说得对，这道题题意太不清楚了

### 代码

```mysql
# Write your MySQL query statement below
#这道题的题解和评论中有很多学习的地方
#笔记：count(列)是不计算Null的。groupby后面的order by是按照group by分组后计算的
select distinct question_id   AS survey_log  
from survey_log 
group by question_id
order by  sum(if(answer_id is null,0,1)) desc limit 1
```##