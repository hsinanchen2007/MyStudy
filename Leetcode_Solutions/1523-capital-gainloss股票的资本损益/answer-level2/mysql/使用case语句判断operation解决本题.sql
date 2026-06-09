### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select stock_name as stock_name, sum(case when operation='Buy' then -1*price else price end) as capital_gain_loss from Stocks group by(stock_name)



```