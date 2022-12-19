```
select c1.visited_on,sum(c2.amount) amount,round(sum(c2.amount)/7,2) average_amount
from 
(select customer_id,name,visited_on,sum(amount) amount from Customer group by visited_on)c1 cross join 
(select customer_id,name,visited_on,sum(amount) amount from Customer group by visited_on) c2 
where datediff(c1.visited_on,c2.visited_on)<7  and datediff(c1.visited_on,c2.visited_on)>=0
group by c1.visited_on
having count(*)>6
order by c1.visited_on
```
先对每个表按日期进行去重求和，然后做笛卡尔积，然后筛选出符合条件的，再之后排序。得到答案
