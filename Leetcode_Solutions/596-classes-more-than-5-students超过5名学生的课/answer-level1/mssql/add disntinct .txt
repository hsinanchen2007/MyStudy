### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */
select class from courses
group by class having count(distinct student)>=5
```