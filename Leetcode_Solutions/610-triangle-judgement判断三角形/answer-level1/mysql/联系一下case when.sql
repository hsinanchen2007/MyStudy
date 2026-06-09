select * , 
case
    when x + y <= z then 'No'
    when x + z <= y then 'No'
    when y + z <= x then 'No'
    else 'Yes'
    end as triangle
from triangle;