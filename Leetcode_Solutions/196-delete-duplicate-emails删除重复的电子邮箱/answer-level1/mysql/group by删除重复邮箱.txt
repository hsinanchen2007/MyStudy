### 解题思路
利用group by函数

### 代码

```mysql
# Write your MySQL query statement below
delete from person
where id not in(
    select * from (select MIN(id) from person group by email )A
)
```