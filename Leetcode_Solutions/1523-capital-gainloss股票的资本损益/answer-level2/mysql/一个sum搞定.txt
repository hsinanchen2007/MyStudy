### 解题思路
如果数据都是buy-sell，那么可以直接考虑计算出所有buy之和,sell之和做计算

### 代码

```mysql
# Write your MySQL query statement below

select stock_name,
    (sum(case when operation='sell' then price else 0 end)-
    sum(case when operation='buy' then price else 0 end )) capital_gain_loss
from Stocks 
group by stock_name
```