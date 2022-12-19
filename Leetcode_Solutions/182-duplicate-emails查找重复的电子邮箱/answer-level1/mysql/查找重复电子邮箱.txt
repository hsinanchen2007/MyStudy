首先查找出所有重复电子邮箱，说明电子邮箱一样但Id不同。所以我们只需要创建一个查询，并且要注意去除重复值
代码
select p1 from Person p1,Person p2 where p1.Id!=p2 and p1.email=p2.email