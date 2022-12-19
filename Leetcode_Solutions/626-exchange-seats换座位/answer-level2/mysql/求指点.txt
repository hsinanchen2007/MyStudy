  select case 
            when a.id%2=0 then id-1
            else a.id+1
         end as id ,student
  from(select *
  from seat 
  where id not in (select max(id) from seat having max(id)%2=1 ))a
  union 
  select * from seat where id in (select max(id) from seat having max(id)%2=1)
  order by id