!!!在MYSQL里，不能先select一个表的记录，在按此条件进行更新和删除同一个表的记录

```
# Write your MySQL query statement below
DELETE from Person 
Where Id not in 
(
    select t.id from   
    -- 加上这个外层筛选可以避免You can't specify target table for update in FROM clause错误
    -- 因为在MYSQL里，不能先select一个表的记录，在按此条件进行更新和删除同一个表的记录
    -- 这个问题只出现于mysql，mssql和oracle不会出现此问题
    -- 解决办法是，将select得到的结果，再通过中间表select一遍，这样就规避了错误，
    (
        Select MIN(Id) as id
        From Person 
        Group by Email
    ) t
)
```
