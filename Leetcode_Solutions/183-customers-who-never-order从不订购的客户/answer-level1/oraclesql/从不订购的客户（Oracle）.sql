方法一：（使用左关联）
select a.Name as Customers
from Customers a
left join Orders b
on a.Id=b.CustomerId
where b.CustomerId is null
order by a.id;

方法二：（使用not in）
select Name as Customers
from Customers
where id not in (select CustomerId from Orders)
order by id;