关于效率……我真不知道如何提高了……
```
SELECT 
id "id",
MAX(DECODE(month,'Jan',revenue,null)) "Jan_Revenue",
MAX(DECODE(month,'Feb',revenue,null)) "Feb_Revenue",
MAX(DECODE(month,'Mar',revenue,null)) "Mar_Revenue",
MAX(DECODE(month,'Apr',revenue,null)) "Apr_Revenue",
MAX(DECODE(month,'May',revenue,null)) "May_Revenue",
MAX(DECODE(month,'Jun',revenue,null)) "Jun_Revenue",
MAX(DECODE(month,'Jul',revenue,null)) "Jul_Revenue",
MAX(DECODE(month,'Aug',revenue,null)) "Aug_Revenue",
MAX(DECODE(month,'Sep',revenue,null)) "Sep_Revenue",
MAX(DECODE(month,'Oct',revenue,null)) "Oct_Revenue",
MAX(DECODE(month,'Nov',revenue,null)) "Nov_Revenue",
MAX(DECODE(month,'Dec',revenue,null)) "Dec_Revenue" 
FROM Department 
GROUP BY id
```
