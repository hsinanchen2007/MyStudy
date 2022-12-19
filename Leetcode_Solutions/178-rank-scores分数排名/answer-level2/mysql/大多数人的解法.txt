这道题其实很简单，我看到很多人使用了窗口函数这些！这个我很久没有写mysql了，就说说最基础的方法吧！但是这种方法也是效率相对来说低一些，不过可以满足题目要求。
首先我们看到rank排名是相同分数必须是相同名次，因此必须得根据Score分数进行去重进行count，那么这个rank排名根据例子可以看出来，基本就是前面去重数字的序列。因此可以直接写出sql：
select 
s.Score , (select if(count(distinct Score)>0,count(distinct Score)+1,1) from Scores where Score>s.Score) as Rank
from Scores s
order by s.Score desc