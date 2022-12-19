select B.book_id,B.name
from Books B left join Orders O
on B.book_id=O.book_id 
where datediff("2019-06-23",B.available_from)>=30
group by B.book_id
having sum(if(datediff("2019-06-23",O.dispatch_date)<=365,O.quantity,0))<10