```
select 
    s.month,
    t.country ,
    sum(if(s.is_char=1,1,0)) as approved_count,
    sum(if(s.is_char=1,amount ,0)) as approved_amount, 
    sum(if(s.is_char=2,1,0)) as chargeback_count ,
    sum(if(s.is_char=2,amount ,0)) as chargeback_amount  
from (select date_format(trans_date,'%Y-%m')  as month,id ,if(state='approved',1,'str') as is_char  from Transactions  union   all select date_format(trans_date,'%Y-%m'), trans_id ,2   from  Chargebacks )s 
left join Transactions  t on t.id=s.id
group by s.month, t.country 
having approved_amount >0  or   chargeback_amount >0;
```
