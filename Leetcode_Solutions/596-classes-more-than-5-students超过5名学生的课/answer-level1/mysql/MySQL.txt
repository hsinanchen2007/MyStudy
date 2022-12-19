### 解题思路
where 关键字不能与聚合函数一起使用，可以用having关键字，一般having在分组之后使用

### 代码

```mysql
# Write your MySQL query statement below

select a.class as class from courses a group by a.class having count(distinct a.student) >=5; 
```