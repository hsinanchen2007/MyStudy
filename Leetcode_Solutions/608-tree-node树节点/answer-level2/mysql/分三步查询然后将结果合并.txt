### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

# 没爹的就是根
select id,"Root" as Type
from tree a
where p_id is null

union all
#上有老下有小
select id,"Inner" as Type
from tree a
where p_id is not null and 
id in (
    select p_id from tree where p_id is not null
)



union all
#没儿子的就是叶子
select id,"Leaf" as Type
from tree a
where id not in (select id from tree where p_id is null)
and id not in (
    select p_id from tree where p_id is not null
)


order by id

```