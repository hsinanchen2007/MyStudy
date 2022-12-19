其实只要统计赚了的总数减去亏损的总数即可
```
select stock_name,sum(if(operation='Sell',price,0))-sum(if(operation='Buy',price,0)) capital_gain_loss from Stocks
group by stock_name
```
