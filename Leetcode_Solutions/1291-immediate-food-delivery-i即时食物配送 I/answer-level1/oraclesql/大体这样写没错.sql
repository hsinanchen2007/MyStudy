select round(A.a/B.b*100,2) immediate_percentage from 
(select count(1) a from delivery t where t.order_date=t.customer_pref_delivery_date) A,
(select count(1) b from delivery t) B