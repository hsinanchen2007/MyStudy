1.根据题意需要获取***和订购情况，所以需要使用连接JOIN
2.可以先找出订购的客户，然后使用NOT IN 找出未订购客户
SELECT C.Name Customer
FROM Customers C
WHERE C.Name NOT IN 
(SELECT C.Name FROM Customers C JOIN Orders O ON C.id = O.Customerid);