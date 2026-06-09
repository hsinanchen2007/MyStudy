
按字面的理解，要查product表的所有产品的销售年和价格。
product表跟sales表左连接，键值product_id相等，再选出所需的三列。

select p.product_name as product_name,s.year as year,s.price as price from Product p left join Sales s on p.product_id=s.product_id

但是这样会遇到一些没有出现在sales表的product，显示null项，答案里没有这些项。

为此可以加个where滤掉null.
不同的选择耗时不同。

where s.product_id is not null;
1700+ms

where s.price is not null;
1400+ms

where s.year is not null;
超时
