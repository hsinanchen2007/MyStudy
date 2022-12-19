### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
select format_trans.month, format_trans.country, sum(if(format_trans.is_approved!=0, 1,0)) as approved_count, sum(format_trans.is_approved) as approved_amount, sum(if(format_trans.is_chargebacked!=0, 1,0)) as chargeback_count, sum(format_trans.is_chargebacked) as chargeback_amount
from 
(select merge_trans.id, merge_trans.country, merge_trans.state, merge_trans.amount, date_format(merge_trans.trans_date, "%Y-%m") as month, if(merge_trans.state='approved', amount, 0) as  is_approved, if(merge_trans.state='chargebacked', amount, 0) as is_chargebacked
from (
    (
    select c.trans_id as id, country, "chargebacked" as state, amount, c.trans_date
    from Transactions as t 
    join Chargebacks as c 
    on c.trans_id = t.id 
    )  union 
    (
    select * from Transactions 
    )
) as merge_trans
) as format_trans
group by format_trans.month, format_trans.country
having approved_count!=0 or approved_amount!=0 or chargeback_count!=0 or chargeback_amount
!=0;

```