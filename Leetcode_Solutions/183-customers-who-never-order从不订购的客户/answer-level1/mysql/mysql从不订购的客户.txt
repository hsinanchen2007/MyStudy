select c.Name as Customers  from  ( select a.Name,b.CustomerId from Customers a left join  Orders b on a.Id = b.CustomerId) as  c where c.CustomerId is null;

使用用户表的左连接筛选出来未订购的用户，此时cusomerid是Null,由于NULL不能直接使用=<>判断，采用关键字is null判断返回值为null，只要customerid为空，即说明该用户从未采购