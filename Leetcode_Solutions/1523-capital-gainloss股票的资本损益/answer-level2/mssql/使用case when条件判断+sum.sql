思路：

只要按照股票名称分组，累计股票买卖价格的结果即可。

注意：<br>
买应当看作是花钱了，所以计算时要用负数；<br>
卖应当看作是进钱了，所以计算时要用正数。<br>
```
select stock_name,
    sum(case when operation='Buy' then (-1)*price else price end) as capital_gain_loss
from Stocks
group by stock_name
```
执行用时 :1602 ms, 内存消耗 :0B