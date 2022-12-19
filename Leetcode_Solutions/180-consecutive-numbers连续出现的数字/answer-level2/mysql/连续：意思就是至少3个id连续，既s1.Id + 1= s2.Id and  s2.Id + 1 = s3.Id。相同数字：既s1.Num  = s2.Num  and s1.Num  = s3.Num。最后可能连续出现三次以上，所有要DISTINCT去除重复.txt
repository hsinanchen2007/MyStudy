### 解题思路
连续：意思就是至少3个id连续，既s1.Id + 1= s2.Id and  s2.Id + 1 = s3.Id。相同数字：既s1.Num  = s2.Num  and s1.Num  = s3.Num。最后可能连续出现三次以上，所有要DISTINCT去除重复
### 代码

```mysql
# Write your MySQL query statement below

select DISTINCT s1.Num as ConsecutiveNums from
Logs s1,logs s2,Logs s3
where s1.Id + 1= s2.Id and  s2.Id + 1 = s3.Id
and s1.Num  = s2.Num  and s1.Num  = s3.Num
```