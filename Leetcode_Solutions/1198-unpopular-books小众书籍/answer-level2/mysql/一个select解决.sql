select books.book_id,books.name 
from  
books left join orders 
on books.book_id=orders.book_id
where datediff("2019-06-23",books.available_from)>=30 
group by books.book_id 
having sum(if(datediff("2019-06-23",dispatch_date)<=365,quantity,0))<10