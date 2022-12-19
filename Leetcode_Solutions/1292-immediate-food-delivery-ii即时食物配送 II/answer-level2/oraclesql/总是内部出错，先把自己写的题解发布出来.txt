1: 找出首次订单数=>首次订单为根据顾客分组 ,选择每组中order_date最小的订单即：每个客户时间最早的第一笔订单

with c as (select t.customer_id,min(order_date) order_date from delivery t group by t.customer_id ) ,

2：把每个客户第一笔订单作为条件，去从delivery源表中筛选出详细信息

with d as (select t.*  from delivery t  where exist(select 1 from c s where s.customer_id=t.customer_id and s.order_date=t.order_date ))

3: 计算 第一笔订单中为即时订单的概率

select round(A.a/B.b*100,2) immediate_percentage from 
(select count(1) a from d t where t.order_date=t.customer_pref_delivery_date) A,
(select count(1) b from d t) B