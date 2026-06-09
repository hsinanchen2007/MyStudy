### 解题思路
此处撰写解题思路
别问，问就是牛逼解法

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select distinct(Num) as ConsecutiveNums from(select Num,id,lag(id,2) over(partition by Num order by id) as id_new from Logs) a where a.id = a.id_new + 2;
```