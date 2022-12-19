### 解题思路
哈哈哈，成功了

### 代码

```mysql
# Write your MySQL query statement below


select
    id
  , if(p_id is null, "Root", if(id in (
                                      select p_id
                                      from tree t2
                                      where p_id is not null
                                      ), "Inner", "Leaf")) Type
from
    tree;
```