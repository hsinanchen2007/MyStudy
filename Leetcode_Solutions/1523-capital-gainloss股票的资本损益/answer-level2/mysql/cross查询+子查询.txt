### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select table1.stock_name,(table1.gain_loss-table2.gain_loss) as capital_gain_loss  
from (select stock_name,operation,sum(price) as gain_loss from stocks
group by stock_name,operation) table1,
(select stock_name,operation,sum(price) as gain_loss from stocks
group by stock_name,operation) table2
where table1.stock_name=table2.stock_name and table1.operation='sell'
and table2.operation='buy'

```