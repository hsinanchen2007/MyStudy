先把公司表和订单表连接起来，然后利用子查询找出向RED公司销售东西的销售员id,然后在从销售员信息表里利用not in子句查出这些id之外的销售员的名字。
```
select name from salesperson 
where sales_id not in(
    select o.sales_id from orders as o left join company as c on o.com_id = c.com_id 
where c.name ='RED'
);
```
