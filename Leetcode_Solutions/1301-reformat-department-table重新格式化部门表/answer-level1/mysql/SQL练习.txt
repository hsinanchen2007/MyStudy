```
# Write your MySQL query statement below
select id,
sum(if(month='Jan', revenue, NULL)) Jan_Revenue,
sum(if(month='Feb', revenue, NULL)) Feb_Revenue,
sum(if(month='Mar', revenue, NULL)) Mar_Revenue,
sum(if(month='Apr', revenue, NULL)) Apr_Revenue,
sum(if(month='May', revenue, NULL)) May_Revenue,
sum(if(month='Jun', revenue, NULL)) Jun_Revenue,
sum(if(month='Jul', revenue, NULL)) Jul_Revenue,
sum(if(month='Aug', revenue, NULL)) Aug_Revenue,
sum(if(month='Sep', revenue, NULL)) Sep_Revenue,
sum(if(month='Oct', revenue, NULL)) Oct_Revenue,
sum(if(month='Nov', revenue, NULL)) Nov_Revenue,
sum(if(month='Dec', revenue, NULL)) Dec_Revenue
from Department
group by id;
```
这道题教给了我如何去实现由行向列的转化，添加新的列，实现表的重构
