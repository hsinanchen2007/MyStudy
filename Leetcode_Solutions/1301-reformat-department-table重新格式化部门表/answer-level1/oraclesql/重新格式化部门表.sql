### 解题思路
1. 使用 group by + sum + decode 进行行转列

### 代码
```oraclesql
select id,
       sum(decode(month, 'Jan', revenue, null)) Jan_Revenue,
       sum(decode(month, 'Feb', revenue, null)) Feb_Revenue,
       sum(decode(month, 'Mar', revenue, null)) Mar_Revenue,
       sum(decode(month, 'Apr', revenue, null)) Apr_Revenue,
       sum(decode(month, 'May', revenue, null)) May_Revenue,
       sum(decode(month, 'Jun', revenue, null)) Jun_Revenue,
       sum(decode(month, 'Jul', revenue, null)) Jul_Revenue,
       sum(decode(month, 'Aug', revenue, null)) Aug_Revenue,
       sum(decode(month, 'Sep', revenue, null)) Sep_Revenue,
       sum(decode(month, 'Oct', revenue, null)) Oct_Revenue,
       sum(decode(month, 'Nov', revenue, null)) Nov_Revenue,
       sum(decode(month, 'Dec', revenue, null)) Dec_Revenue
from Department d
group by id
```