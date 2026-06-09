### 解题思路
直接用普通的select查询和限定条件语句就能查出

### 代码

```mysql
# Write your MySQL query statement below
select name,population,area from World where area > 3000000 or population > 25000000;
```