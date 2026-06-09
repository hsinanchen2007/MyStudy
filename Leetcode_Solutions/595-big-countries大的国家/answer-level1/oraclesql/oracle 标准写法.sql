### 解题思路
或者条件查询
### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select name , population , area from World where area>3000000 or population>25000000;
```