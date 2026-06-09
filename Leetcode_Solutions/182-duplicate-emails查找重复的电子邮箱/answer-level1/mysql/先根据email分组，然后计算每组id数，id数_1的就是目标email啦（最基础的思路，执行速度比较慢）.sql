### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select email
from person
where id in
  (select id
  from person
  group by email
  having count(id)>1)
```