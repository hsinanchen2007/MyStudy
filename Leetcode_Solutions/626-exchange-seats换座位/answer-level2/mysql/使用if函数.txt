### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select 
    if(id%2=0,id-1,
        if(id=(select max(id) from seat),id,id+1)
    ) as id,
    student
    from seat
    order by id;
```

卧槽,第一次在数据库中使用 if 函数.....