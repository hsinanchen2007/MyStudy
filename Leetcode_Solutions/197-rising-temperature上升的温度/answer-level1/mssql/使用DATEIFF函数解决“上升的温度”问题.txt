### 解题思路
dateiff()函数用来执行日期的加减，这里使用inner join将表与自身求交集，筛选条件是今天的温度比昨天高。

### 代码

```mssql
/* Write your T-SQL query statement below */
select w1.Id Id from Weather w1
inner join Weather w2 
on datediff(day,w2.RecordDate,w1.RecordDate) = 1 and w1.Temperature > w2.Temperature 
```