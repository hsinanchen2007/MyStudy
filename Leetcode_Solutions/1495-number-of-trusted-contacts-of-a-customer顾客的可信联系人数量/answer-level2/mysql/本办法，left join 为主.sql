### 解题思路
此处撰写解题思路

### 代码

```mysql
-- # Write your MySQL query statement below
SELECT b1.invoice_id, b2.name1 AS customer_name, b1.price, b2.contacts_cnt, b2.trusted_contacts_cnt
FROM Invoices b1 JOIN
(SELECT a1.customer_id, a1.name1, a1.contacts_cnt, a2.trusted_contacts_cnt
FROM
(SELECT t1.customer_id, t1.customer_name AS name1, COUNT(t2.contact_name) AS contacts_cnt 
FROM Customers t1 LEFT JOIN Contacts t2
ON t1.customer_id = t2.user_id
GROUP BY t1.customer_id) a1
JOIN
(SELECT m1.customer_id, m1.customer_name AS name2, COUNT(m2.contact_name) AS trusted_contacts_cnt
-- m1.customer_id, m1.customer_name AS name2, COUNT(m2.contact_name) AS trusted_contacts_cnt
    FROM Customers m1 LEFT JOIN 
        (SELECT * 
        FROM Contacts
        WHERE contact_name IN (SELECT customer_name FROM Customers)) AS m2
    ON m1.customer_id = m2.user_id     
    GROUP BY m1.customer_id) a2
ON a1.customer_id = a2.customer_id) b2
ON b1.user_id = b2.customer_id
ORDER BY b1.invoice_id ASC

```
先把直接联系人算出来，然后用IN 的办法来filter掉不在customers 里的contacts，再算一次
然后和invoice进行left join。