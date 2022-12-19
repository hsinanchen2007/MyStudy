select c.Name Customers  from Customers c
left join Orders o on c.id = o.CustomerId 
where o.id is null


 执行左关联,查找订单号为null的就可以了(464ms  94.64%)