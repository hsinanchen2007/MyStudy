-- //查出每个人的联系人数
-- (select count(user_id) contacts_cnt, user_id
-- from Contacts
-- group by user_id) t1

-- //查出每个人的可信联系人数
-- (select user_id, count(user_id) trusted_contacts_cnt
-- from Customers, Contacts
-- where Customers.customer_name = Contacts.contact_name
-- group by user_id) t2

-- Customers left join (t1 join t2 on t1.user_id = t2.user_id) 做个左连接出一张 表1

-- select * from
-- Customers left join ((select count(user_id) contacts_cnt, user_id
-- from Contacts
-- group by user_id) t1 left join (select user_id, count(user_id) trusted_contacts_cnt
-- from Customers, Contacts
-- where Customers.customer_name = Contacts.contact_name
-- group by user_id) t2 on t1.user_id = t2.user_id)
-- on Customers.customer_id =  t1.user_id  将顾客表跟表一做左连接 表二

<!-- 最终答案 -->
<!-- 最后用订单表链接上面的表二  -->
select invoice_id, Customers.customer_name, price, ifnull(contacts_cnt, 0) contacts_cnt, ifnull(trusted_contacts_cnt, 0) trusted_contacts_cnt
from Invoices left join (Customers left join ((select count(user_id) contacts_cnt, user_id
from Contacts
group by user_id) t1 left join (select user_id, count(user_id) trusted_contacts_cnt
from Customers, Contacts
where Customers.customer_name = Contacts.contact_name
group by user_id) t2 on t1.user_id = t2.user_id)
on Customers.customer_id =  t1.user_id)
on Invoices.user_id = Customers.customer_id
order by invoice_id


