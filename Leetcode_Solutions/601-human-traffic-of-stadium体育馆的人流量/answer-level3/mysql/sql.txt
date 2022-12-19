select e.id,e.visit_date,e.people
from(select *
     from
      (
         select a.id,a.visit_date,min(b.people) as people
         from stadium a join stadium b
         on b.id-a.id between 0 and 2
         group by a.visit_date 
        )c
where c.people >=100
     )d
 join stadium e
 on d.id=e.id