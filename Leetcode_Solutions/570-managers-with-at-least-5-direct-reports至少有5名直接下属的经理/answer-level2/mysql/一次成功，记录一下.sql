### 解题思路
通过分组 group by...having count()... 语句找到至少有5个相同的managerId
再查询 Id 是否在上面的查询结果中即可。

### 代码

```mysql
# Write your MySQL query statement below
select e1.Name
from Employee e1
where e1.Id in (
    select e2.ManagerId
    from Employee e2
    group by e2.ManagerId having count(*)>=5
)
;
```