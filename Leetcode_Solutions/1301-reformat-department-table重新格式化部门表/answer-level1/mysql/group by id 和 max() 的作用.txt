### 解题思路
用 group by id 分组之后，需要用聚合函数进行计算，此处用 max（）即可

### 代码

```mysql
# Write your MySQL query statement below
select
    id,
    max(if(month='Jan',revenue,NULL)) as "Jan_Revenue",
    max(if(month='Feb',revenue,NULL)) as "Feb_Revenue",
    max(if(month='Mar',revenue,NULL)) as "Mar_Revenue",
    max(if(month='Apr',revenue,NULL)) as "Apr_Revenue",
    max(if(month='May',revenue,NULL)) as "May_Revenue",
    max(if(month='Jun',revenue,NULL)) as "Jun_Revenue",
    max(if(month='Jul',revenue,NULL)) as "Jul_Revenue",
    max(if(month='Aug',revenue,NULL)) as "Aug_Revenue",
    max(if(month='Sep',revenue,NULL)) as "Sep_Revenue",
    max(if(month='Oct',revenue,NULL)) as "Oct_Revenue",
    max(if(month='Nov',revenue,NULL)) as "Nov_Revenue",
    max(if(month='Dec',revenue,NULL)) as "Dec_Revenue"
from
    Department
group by id;
```