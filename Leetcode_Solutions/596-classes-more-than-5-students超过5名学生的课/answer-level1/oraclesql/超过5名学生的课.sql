```
/* Write your PL/SQL query statement below */
select class from courses having count(distinct student)>=5 group by class
```
