select distinct  a.month, a.country,ifnull(b.approved_count,0) as approved_count,    # 加了distinct，是最终结果中可能会有重复值
ifnull(b.approved_amount,0) as approved_amount, ifnull(c.chargeback_count,0) as chargeback_count,
 ifnull(c.chargeback_amount,0) as chargeback_amount

from
(select date_format(T.trans_date,'%Y-%m')as month, T.country as country from  Transactions as T   
group by month(T.trans_date),T.country
union all
select date_format(C.trans_date,'%Y-%m')as month , T.country as country 
from Chargebacks as C join Transactions as T on C.trans_id=T.id
group by month(C.trans_date),T.country) a


left join

(select date_format(T.trans_date,'%Y-%m') as month ,T.country, count(T.id) as approved_count, sum(T.amount)  as approved_amount
from  Transactions as T
where T.state='approved'
group by month(T.trans_date) ,T.country) b on  a.month=b.month and a.country=b.country

left join 

(select date_format(C.trans_date,'%Y-%m') as month,T.country, count(T.id) as chargeback_count ,sum(T.amount) as chargeback_amount
from Transactions as T join Chargebacks as C on T.id=C.trans_id
group by month(C.trans_date),T.country) c on a.month=c.month  and a.country=c.country

where isnull(b.approved_count)+isnull(c.chargeback_count)<2  # 判断非零行
order by a.month;