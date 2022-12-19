select 
    id,
    max(decode(month, 'Jan', revenue, null)) as Jan_Revenue,
    max(decode(month, 'Feb', revenue, null)) as Feb_Revenue,
    max(decode(month, 'Mar', revenue, null)) as Mar_Revenue,
    max(decode(month, 'Apr', revenue, null)) as Apr_Revenue,
    max(decode(month, 'May', revenue, null)) as May_Revenue,
    max(decode(month, 'Jun', revenue, null)) as Jun_Revenue,
    max(decode(month, 'Jul', revenue, null)) as Jul_Revenue,
    max(decode(month, 'Aug', revenue, null)) as Aug_Revenue,
    max(decode(month, 'Sep', revenue, null)) as Sep_Revenue,
    max(decode(month, 'Oct', revenue, null)) as Oct_Revenue,
    max(decode(month, 'Nov', revenue, null)) as Nov_Revenue,
    max(decode(month, 'Dec', revenue, null)) as Dec_Revenue   
from Department
group by id