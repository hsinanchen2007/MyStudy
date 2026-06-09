### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select temp.class from
((select class, count(distinct student) as class_counts from courses group by class) as temp)
where temp.class_counts >= 5;
```