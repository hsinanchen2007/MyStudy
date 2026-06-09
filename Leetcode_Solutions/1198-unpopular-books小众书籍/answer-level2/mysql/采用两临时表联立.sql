select t1.book_id,t1.name from 
(select book_id,name from books where datediff('2019-06-23',available_from) > 31) t1 
left join 
(select book_id,sum(quantity) sum_qua from orders where dispatch_date between '2018-06-23' and '2019-06-23' group by book_id) t2
on t1.book_id=t2.book_id where t2.sum_qua < 10 or t2.sum_qua is null