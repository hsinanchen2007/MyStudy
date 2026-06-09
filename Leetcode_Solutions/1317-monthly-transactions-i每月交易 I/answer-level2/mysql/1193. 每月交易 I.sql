### 解题思路
此处撰写解题思路
这道题重点在于如何将日期按照月份聚合
使用 DATE_FORMAT(trans_date, '%Y-%m') 即可
其他条件无非就是sum(if()) , count() 的使用
### 代码

```mysql
# Write your MySQL query statement below

select DATE_FORMAT(trans_date, '%Y-%m')  as month,
       country ,
       count(state) as trans_count,
       sum(if(state = "approved",1,0)) as approved_count ,
       sum(amount) as trans_total_amount ,
       sum(if(state = "approved",amount,0)) as approved_total_amount  
from Transactions t
group by extract(year from trans_date),extract(month from trans_date),country
```