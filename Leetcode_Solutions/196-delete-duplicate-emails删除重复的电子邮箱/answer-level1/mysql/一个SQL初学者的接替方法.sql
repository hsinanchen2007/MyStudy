### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
# 删除数据时不能根据直接查询出来的条件进行删除
# 将查询出来的结果作为一个临时表进行查询即可
delete from 
Person
where Id not in (
    select 
    Id
    from (
        select
        min(Id) as Id
        from 
        Person
        group by
        Email
    ) as temp
)


```