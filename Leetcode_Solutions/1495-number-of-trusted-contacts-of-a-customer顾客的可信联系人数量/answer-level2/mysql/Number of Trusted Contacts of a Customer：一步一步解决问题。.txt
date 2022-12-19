### 子查询1

查询 invoice_id, customer_name , price  这些字段基本信息。
只需要根据Invoices 表的 user_id  左链接 customer 表，得到customer_name的信息
并排序。
```mysql
SELECT Invoices.invoice_id, Customers.customer_name, Invoices.price
FROM Invoices
LEFT JOIN Customers 
ON Invoices.user_id = Customers.customer_id
ORDER BY Invoices.invoice_id
```

结果如下

```shell
["invoice_id", "customer_name", "price"]
[44, "Alex", 60] 
[55, "John", 500] 
[66, "Bob", 400]
[77, "Alice", 100] 
[88, "Alice", 200] 
[99, "Bob", 300]
```

### 子查询2：

对于`trusted_contacts_cnt`的定义，题目描述，His/Her email exists in the Customers table.), 因此我们可以根据email字段左连接Contacts table，在临时试图中得到customer_id, 注意因为是 `LEFT JOIN`,所以对于Contacts表的某个数据如果其email没有出现在 Contact 表中,则其 customer_id 为 `null`.

```mysql
SELECT Contacts.user_id, Customers.customer_id
FROM Contacts
LEFT JOIN Customers
ON Contacts.contact_email = Customers.email
```

结果如下

```shell
["user_id", "customer_id"]
[1, 2] 
[1, 13]
[1, null] 
[2, null]
[2, null]
[6, 1]
```

之后我们便可以对 user_id 进行分组并统计，**由于`COUNT(字段)`不会统计字段值为null值的数据**， 所以对 customer_id 统计结果正好可以得出trusted的数量，（当然这里用`SUM`函数也可以）。

``` mysql
SELECT Contacts.user_id, COUNT(Contacts.user_id) AS contacts_cnt, COUNT(Customers.customer_id) AS trusted_contacts_cnt
FROM Contacts
LEFT JOIN Customers
ON Contacts.contact_email = Customers.email
GROUP BY user_id
```

结果如下
```shell
["user_id", "contacts_cnt", "trusted_contacts_cnt"]
[1, 3, 2]
[2, 2, 0]
[6, 1, 1]
```


### 合并子查询结果

接下来，只要将它们两个合并起来就可以了,

最终代码如下：

```mysql
SELECT Invoices.invoice_id, Customers.customer_name, Invoices.price, 
IFNULL(`contacts_cnt`,0) AS contacts_cnt,
IFNULL(`trusted_contacts_cnt`,0) AS trusted_contacts_cnt
FROM Invoices
LEFT JOIN Customers 
ON Invoices.user_id = Customers.customer_id
LEFT JOIN (
    SELECT Contacts.user_id, COUNT(Contacts.user_id) AS contacts_cnt, COUNT(Customers.customer_id) AS trusted_contacts_cnt
    FROM Contacts
    LEFT JOIN Customers
    ON Contacts.contact_email = Customers.email
    GROUP BY user_id
) AS V
ON Invoices.user_id = V.user_id
ORDER BY Invoices.invoice_id
```















