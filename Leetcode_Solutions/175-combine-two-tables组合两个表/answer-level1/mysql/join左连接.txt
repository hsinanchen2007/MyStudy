### 解题思路

join 连接不依赖关联表是否有数据，从题目的描述用左连接就可以。Person表和Address的主键和外键都是personId
通过关联查询即可。

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName,p.LastName,a.City,a.State from Person p left join Address
a on p.PersonId = a.PersonId
```
