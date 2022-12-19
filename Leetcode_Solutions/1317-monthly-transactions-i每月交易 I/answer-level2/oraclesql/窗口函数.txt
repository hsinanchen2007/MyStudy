```
/* Write your PL/SQL query statement below */
select distinct month,country,
    count(*) over(partition by month,country) trans_count,
    sum(decode(state,'approved',1,0)) over(partition by month,country) approved_count,
    sum(amount) over(partition by month,country) trans_total_amount,
    sum(decode(state,'approved',amount,0)) over(partition by month,country) approved_total_amount
from (
    select id,country ,state,amount,trans_date,to_char(trans_date,'yyyy-mm') month    
    from Transactions
    )
order by month;
```
