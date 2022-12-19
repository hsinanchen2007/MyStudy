# Write your MySQL query statement below
select d1.month,d1.country,
sum(d1.approved_count) as approved_count,
sum(d1.approved_amount) as approved_amount,
sum(d1.chargeback_count) as chargeback_count,
sum(d1.chargeback_amount) as 
chargeback_amount
from (
  select date_format(t1.trans_date,'%Y-%m') as month,t1.country,
         count(*) as approved_count,
         sum(t1.amount) as approved_amount,
         0 as chargeback_count,
         0 as chargeback_amount 
  from Transactions t1 
  where t1.state='approved'
  group by date_format(t1.trans_date,'%Y-%m') ,country

union all

select 
  date_format(c1.trans_date,'%Y-%m') as month,t2.country, 0 as approved_count,
  0 as approved_amount,
  count(*) as chargeback_count,
  sum(t2.amount) as chargeback_amount
  from Chargebacks c1
  left join   Transactions t2 
  on c1.trans_id=t2.id
  group by  date_format(c1.trans_date,'%Y-%m') ,t2.country
) d1 group by d1.month,d1.country 
 

