```
select id, company, salary
from (select *, row_number() over(partition by company order by salary ASC, id ASC) as rowasc,
     row_number() over(partition by company order by salary DESC, id DESC) as rowdesc from Employee) as temp
where rowasc in (rowdesc, rowdesc-1, rowdesc+1)
order by company, salary
```
