### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

delete from Person where Id not in ( select * from (select  min(id) from Person  group by Email )as c);
```