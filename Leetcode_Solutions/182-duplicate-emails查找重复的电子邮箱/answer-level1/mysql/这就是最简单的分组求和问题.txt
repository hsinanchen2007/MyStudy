### 解题思路
最基础的group by和having语句，没啥好说的
使用group by 分组，使用having 做为聚合查询条件
在结果集合中将分组字段返回

### 代码

```mysql
# Write your MySQL query statement below

select Email from Person group by Email having count(Id) > 1


```