### 解题思路
1.选择name,population,area限制条件为population > 25000000 或者 area > 3000000

### 代码

```mysqlp
# Write your MySQL query statement below
SELECT name,population,area
FROM World
WHERE population > 25000000 OR area > 3000000;
```