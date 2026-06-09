用oracle偏移分析函数lag/lead, 一列查出当前行及上/下行，再通过case判断。
```
select id,
       (case
         when mod(rn, 2) = 1 and s3 is not null then
          s3
         when mod(rn, 2) = 1 and s3 is null then
          s2
         else
          s1
       end) as student
  from (select id, lag(student, 1, null) over(order by id) as s1,
               student s2,
               lead(student, 1, null) over(order by id) as s3,
               rownum as rn
          from seat)