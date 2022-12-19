select a.book_id,a.name 
from Books a 
where  a.book_id 
not in (select b.book_id 
        from (select * 
              from Orders 
              where dispatch_date >= DATE_ADD('2019-06-23',INTERVAL -1 YEAR))b  
group by b.book_id   
having sum(b.quantity)>=10 ) 
and available_from< DATE_ADD('2019-06-23',INTERVAL -1 MONTH)