### 解题思路
题目：编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。
题解：
重复的Email，意思Email的个数是1个以上，需要用到聚集函数count;聚集函数需要用到分组语句group by ,用having过滤结果。

### 代码

```mysql
select Email 
from Person
group by Email
having count(*) > 1




```