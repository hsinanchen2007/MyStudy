```sql
select
    o.id,
    case
        when o.p_id is null then 'Root'
        when not exists(select 1 from tree i where o.id = i.p_id) then 'Leaf'
        else 'Inner'
    end as Type
from tree o
```
