### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select distinct a.num as ConsecutiveNums from Logs a,Logs b,Logs c
where a.id = b.id-1 and b.id=c.id-1
  and a.num = b.num and b.num = c.num;

```