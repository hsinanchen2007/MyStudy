### 解题思路
先对Weather与其自身做内连接，on两个日期相差1（a比b大一天），where a的温度大于b的温度

### 代码

```mysql
# Write your MySQL query statement below
select a.Id from Weather as a inner join Weather as b on datediff(a.RecordDate, b.RecordDate)=1 where a.Temperature > b.Temperature; 
```