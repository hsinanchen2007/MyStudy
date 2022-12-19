```
/* Write your T-SQL query statement below */

select id,
    max(case month when 'Jan' then revenue else null end) 'Jan_Revenue',
    max(case month when 'Feb' then revenue else null end) 'Feb_Revenue',
    max(case month when 'Mar' then revenue else null end) 'Mar_Revenue',
    max(case month when 'Apr' then revenue else null end) 'Apr_Revenue',
    max(case month when 'May' then revenue else null end) 'May_Revenue',
    max(case month when 'Jun' then revenue else null end) 'Jun_Revenue',
    max(case month when 'Jul' then revenue else null end) 'Jul_Revenue',
    max(case month when 'Aug' then revenue else null end) 'Aug_Revenue',
    max(case month when 'Sep' then revenue else null end) 'Sep_Revenue',
    max(case month when 'Oct' then revenue else null end) 'Oct_Revenue',
    max(case month when 'Nov' then revenue else null end) 'Nov_Revenue',
    max(case month when 'Dec' then revenue else null end) 'Dec_Revenue'
from Department
group by id

```