```
select class from (select DISTINCT(concat(student,class)) as combine,student,class from courses) as temp  group by class having count(class)>=5;
```
