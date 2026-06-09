先明确题目第一个要求“删除”
SQL的删除是DELETE语句
`DELETE FROM 表名称 WHERE 列名称 = 值`

**审题：**
题目要求是删除重复的电子邮箱email，并且保留重复邮箱中对应id最小的那一行。

**现在开始笨蛋解题：**
看到*重复的电子邮箱*，冒出的想法有：
1. distinct 行不行？distinct筛选之后，只能返回目标条目即email而无法返回id，目前没有明确思路，先放下
2. group by 行不行？group by之后，email在一栏，左栏则是被group起来的id们，对这些id进行筛选似乎可以实现
那么此处就group by(Email)
结果大致是：
```
| Id   |     Email     |
|------|---------------|
| 1    | hahah@qq.com  |
| 4    | hahah@qq.com  |
| 7    | hahah@qq.com  |
|------|---------------|
| 2    | xxixi@qq.com  |
| 5    | xxixi@qq.com  |
```
那么此刻如果求一个min(id)，刚好就把我们所需要的东西提出来了：[一个最小id+一个Email]，思路好像明确了
唯一就是题目要求我们以删除的方式来得到所需，那么稍微绕一下，让我们删掉的东西不在`not in`这个表里就ok了

那么可行的思路就是：
第一步：先把表中每个email组（group之后自动过滤了重复）的最小id搞出来
`select min(Id) from Person  group by Email`
这个select得到的表的id就是所有我们需要保留的id，那么在原表中，把这一部分id拿掉（not in）就可以了

**开始写SQL：**
因为我们需要保留的id需要被保留进一个虚拟表里，所以先把这个表弄出来，并分装：
`(select min(Id) as id from Person  group by Email) as need --就叫它need`
但是此时的need是一张表，我们要进行比较的need.id
所以要把need表的id提取出来
即为：
`(select need.id from ((select min(Id) as id from Person  group by Email) as need ))`
上述则把这个表中的id选取了出来
我们需要的是删除：
```
delete from Person
where id not in 
(select need.id from 
((select min(Id) as id from Person  group by Email) as need ))
```
以上便是题解
以下画个类似Venn图来解释一下思路

![IMG_0045.jpeg](https://pic.leetcode-cn.com/7a88c40a3ab636403ce9b28199d4703b966ea2fce3bf943b9d0bf5464fe2ccc4-IMG_0045.jpeg)

----
对于not in的一点优化
处理大量数据时，in的效率远不及exists
所以尝试优化一下not in部分
尝试失败了...
希望有大佬看到的话给出一点用exists改进的意见





