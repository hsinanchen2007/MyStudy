### 解题思路
此处撰写解题思路

### 代码
为什么 (select min(Id) as Id  from Person group by Email ) temp不加临时表会报错？？
```mysql
# Write your MySQL query statement below
delete from  Person where Id Not in ( select Id from  (select min(Id) as Id  from Person group by Email ) temp)
```