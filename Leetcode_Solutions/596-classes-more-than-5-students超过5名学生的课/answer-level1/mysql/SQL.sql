### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below


SELECT class from  (seleCT class, count(distinct student) as num from courses group by class ) as tmp  where num>=5;

```