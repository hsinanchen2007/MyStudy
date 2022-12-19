### 解题思路
此题主要考验的是date_format函数的应用 ，其他的没啥挑战的，需要注意的是结尾要排序一下下
### 代码

```mysql
# Write your MySQL query statement below
select date_format(trans_date,"%Y-%m") as `month`,
country,
count(*) as trans_count,
sum(case when state = 'approved' then 1 else 0 end) as approved_count,
sum(amount) as trans_total_amount,
sum(case when state = 'approved' then amount else 0 end) as approved_total_amount 
from Transactions group by country, DATE_FORMAT(trans_date,"%Y-%m")
order by DATE_FORMAT(trans_date,"%Y-%m") asc

```