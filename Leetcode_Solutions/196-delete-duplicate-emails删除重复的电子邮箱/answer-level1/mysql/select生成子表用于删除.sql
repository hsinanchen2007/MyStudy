### 解题思路
通过本题我学到了可以通过select生成子表的方式去进行删除操作

### 代码

```mysql
# Write your MySQL query statement below
delete
from person
where id not in(select target.id from (select min(id) id
from person
group by email) as target);
```