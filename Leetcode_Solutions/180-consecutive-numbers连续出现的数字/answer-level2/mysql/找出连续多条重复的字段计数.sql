### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select distinct a.Num AS ConsecutiveNums 
from Logs a,Logs b,Logs c
where a.Id= b.Id-1
and b.Id = c.Id-1
and a.Num = b.Num
and b.Num =c.Num;
```
可以通过画图的方式找到规律，利用ID的特点，如何是连续id的话，那么就会出现“下一个id”与原id一致，“下下个id”与“下一个id”一致，使用自连接的方式，设定连接添加。在用distinct去重，得到num的值