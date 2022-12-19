```

select  FORMAT( (select count(*) from Delivery where order_date = customer_pref_delivery_date)/(select count(*) from Delivery)*100,2) + 0  as immediate_percentage

```