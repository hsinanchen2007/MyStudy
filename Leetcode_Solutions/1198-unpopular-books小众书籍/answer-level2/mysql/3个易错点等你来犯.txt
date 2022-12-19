# Write your MySQL query statement below
#易错点：
#（1）容易忽略销量为0的书籍
#（2）使用左链接，但是限制"近一年“使用了where字段，导致销量为null依然被忽略
#（3）having条件忘记is null，导致销量为null被忽略
select t1.book_id,name
from (select b.book_id,name,sum(quantity) as total_q
from Books b left join Orders o
on b.book_id=o.book_id
and dispatch_date>='2018-06-23' and dispatch_date<='2019-06-23'
group by book_id
having total_q<10 or total_q is null) t1
where t1.book_id not in (select book_id from Books where date_add(available_from,interval 1 month)>='2019-06-23')
