思路是先用Invoices和Customers 连接取得名字，再用Invoices和Customers连接取得数量，感觉能四个表连，Customers连两次，懒得写了
```
select t1.invoice_id,t1.customer_name,t1.price,
if(t2.contacts_cnt is null,0,contacts_cnt) contacts_cnt,
if(t2.trusted_contacts_cnt is null,0,trusted_contacts_cnt) trusted_contacts_cnt
from 
(
select i.invoice_id,c1.customer_name,i.price,i.user_id
from 
Invoices i left join Customers c1 on i.user_id =c1.customer_id 
) t1 
left join
(
select c2.user_id,count(*) contacts_cnt,sum(if(c3.email is null,0,1)) trusted_contacts_cnt
from Contacts c2 left join Customers c3 on c2.contact_email=c3.email
group by c2.user_id
) t2
on t1.user_id=t2.user_id 
order by t1.invoice_id
```

