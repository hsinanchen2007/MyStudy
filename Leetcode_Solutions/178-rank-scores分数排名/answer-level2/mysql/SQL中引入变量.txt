### 解题思路
这是我头一次了解到sql语言中是可以使用变量的，变量可以使得sql语言更加灵活
对于本题的解题思路，我不多分享，这并不是本题的难点
本题难点在于语言的运用以及数据类型的掌握

首先通过case语句实现分支
其次在from语句中进行变量的初始化
最后用@所表示的变量进行相关操作


### 代码

```mysql
# Write your MySQL query statement below
select Score, 
case 
when @prescore=score then @currentscore+0
when @prescore:=score then @currentscore:=@currentscore+1
else @currentscore:=@currentscore+1
end as Rank
from scores,
(select @prescore:=NULL, @currentscore:=0) R
order by score desc;
```