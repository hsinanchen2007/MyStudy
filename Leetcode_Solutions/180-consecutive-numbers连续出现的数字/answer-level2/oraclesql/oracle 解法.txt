select distinct num ConsecutiveNums 
from (
      select 
      num,
      count(*) num_count
      from ( 
        select 
        id,
        num,
        row_number() over (order by id) - row_number() over (partition by num order by id) x 
        from logs 
      )
      group by num,x 
      order by min(id);
  )
where num_count >=3