
select project_id

from project

group by project_id

having count(*) = 

(

select max(num)

from

(select project_id,count(*) num

from project

group by project_id)t

)