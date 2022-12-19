```
# Write your MySQL query statement below
(
select ifnull(t1.month,t2.month) month,ifnull(t1.country,t2.country) country,ifnull(approved_count,0) approved_count,ifnull(approved_amount,0) approved_amount,ifnull(chargeback_count,0)chargeback_count,ifnull(chargeback_amount,0) chargeback_amount
from
(
    select date_format(trans_date,"%Y-%m") month,country,count(*) approved_count, sum(amount) approved_amount,0 as tag
from transactions 
where state = 'approved'
group by date_format(trans_date,"%Y-%m"),country

) t1

 left join 

(
select date_format(c.trans_date,"%Y-%m") month,country,count(*) chargeback_count, sum(amount) chargeback_amount
from transactions t right join chargebacks c on t.id = c.trans_id
group by date_format(c.trans_date,"%Y-%m") ,country
) t2
on t1.month = t2.month and t1.country = t2.country)
union
(
select ifnull(t1.month,t2.month),ifnull(t1.country,t2.country),ifnull(approved_count,0),ifnull(approved_amount,0),ifnull(chargeback_count,0),ifnull(chargeback_amount,0)
from
(
    select date_format(trans_date,"%Y-%m") month,country,count(*) approved_count, sum(amount) approved_amount,0 as tag
from transactions 
where state = 'approved'
group by date_format(trans_date,"%Y-%m"),country

) t1 right join 
(
select date_format(c.trans_date,"%Y-%m") month,country,count(*) chargeback_count, sum(amount) chargeback_amount
from transactions t right join chargebacks c on t.id = c.trans_id
group by date_format(c.trans_date,"%Y-%m") ,country
) t2
on t1.month = t2.month and t1.country = t2.country)
```

思路大致就是先算approved的再算chargeback的，然后再用union完成mysql力不能full outer join这个问题。
但是我觉得这种写法是有问题的，默认了chargeback的退款日期跟approve不在同一个月。加入一个id在5月下单，这一单approve了，然后退款也在5月退了，那么我这种解法我觉得好像可能是不对。
粗略的看了别人的几个解法好像都没有谈到这个问题。。