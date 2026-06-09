select book_id,name
from Books  
where book_id not in (select book_id from Orders  
where dispatch_date between '2019-06-23'-interval 1 year and '2019-06-23'
group by book_id having sum(quantity)>=10) and available_from<'2019-06-23'-interval 1 month;