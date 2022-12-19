```sql
-- 此方法比  HAVING 高效
select 
distinct a.Email 
from 
Person as a,Person as b
where a.email = b.email
and a.Id != b.Id

```