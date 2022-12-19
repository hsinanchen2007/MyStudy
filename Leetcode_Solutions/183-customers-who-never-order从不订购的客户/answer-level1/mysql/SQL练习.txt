```
select name as customers from customers
where customers.id not in
(select customers.id from customers, orders
where customers.id=orders.customerid);
```
一开始写的name去对比，结果题目数据中有重名现象，所以正确方法就是利用主键去做补集的选取