### 解题思路
此处撰写解题思路
交叉连接后，通过 where 语句选出 日期相差为 1 并且 温度大于前一天的
### 代码

```T-SQL
# Write your T-SQL query statement below
select b.Id
	from weather as a cross join weather as b 
	where datediff(day,a.RecordDate, b.RecordDate) = 1 
	and a.Temperature < b.Temperature

```