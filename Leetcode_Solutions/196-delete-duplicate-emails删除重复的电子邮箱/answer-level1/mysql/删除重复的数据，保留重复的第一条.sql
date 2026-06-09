### 解题思路
为什么要再一次查询？
答：要先将查询出的ID缓存起来，再根据此ID删除，因为mysql 不能先将select出表中的某些值，再这更新个表!
为什么要重命名t2？
不起别名会报错，需要一个额外的命名空间。


### 代码

```mysql
# Write your MySQL query statement below

DELETE from Person 
Where Id not in (
    Select Id 
    From(
    Select MIN(Id) as id
    From Person 
    Group by Email
   ) t2
)
```