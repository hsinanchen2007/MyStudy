#无窗口函数的实现
#组内操作：分组+插入计算型子查询
select c1.visited_on,
(select sum(c2.amount) from Customer c2 where c2.visited_on<=c1.visited_on and c2.visited_on>=date_add(c1.visited_on,interval -6 day) )amount,
(select round(sum(c2.amount)/7,2) from Customer c2 where c2.visited_on<=c1.visited_on and c2.visited_on>=date_add(c1.visited_on,interval -6 day) )average_amount
from Customer c1
where  visited_on in
(select visited_on
from Customer
where visited_on >=(select date_add(min(visited_on),interval 6 day) from Customer))
group by c1.visited_on
