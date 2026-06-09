
用join先求出联系人也是消费用户的组，计算每个trusted_contacts_cnt ，再在contacts表里分组算出每个用户有多少个联系人，最后三个leftjoin把每个表一连..用ifnull把null换成0，中等难度的题还是没有难题恶心.....难题要恶心到30多行...这才16行。。。
```
select i.invoice_id, c1.customer_name, i.price, ifnull(t.contacts_cnt,0) contacts_cnt,
ifnull(t2.trusted_contacts_cnt, 0) trusted_contacts_cnt 
from invoices i
left join customers c1
on i.user_id = c1.customer_id
left join 
(select user_id, count(*) contacts_cnt from contacts group by user_id) t
on c1.customer_id = t.user_id
left join 
(select c3.user_id,  count(*) trusted_contacts_cnt 
from contacts c3, customers c2
where c3.contact_email = c2.email 
group by c3.user_id) t2
on i.user_id = t2.user_id
order by i.invoice_id
```
