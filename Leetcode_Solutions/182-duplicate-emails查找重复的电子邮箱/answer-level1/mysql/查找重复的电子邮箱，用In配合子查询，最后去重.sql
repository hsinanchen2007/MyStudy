### 解题思路
用In配合子查询，最后去重即可

### 代码

```mysql
# Write your MySQL query statement below

select distinct a.Email from Person a where a.Email in (
    select Email from Person b where b.Email = a.Email and b.Id != a.Id
)
```