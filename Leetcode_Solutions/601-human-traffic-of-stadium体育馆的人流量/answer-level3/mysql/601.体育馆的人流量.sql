方法：**连续n天达标问题**：使用n次自连接。

```MySQL
select distinct s1.*
from stadium s1, stadium s2, stadium s3
where s1.people >= 100 and s2.people >= 100 and s3.people >= 100    -- 先筛选出符合要求的观测
    and (s3.id - s2.id = 1 and s3.id - s1.id = 2 and s2.id - s1.id = 1    -- s1, s2, s3  (从s1开始的高峰期)
         or 
         s2.id - s1.id = 1 and s2.id - s3.id = 2 and s1.id - s3.id = 1    -- s3, s1, s2  (s1在高峰期的第2天)
         or 
         s1.id - s2.id = 1 and s1.id - s3.id = 2 and s2.id - s3.id = 1    -- s3, s2, s1  (s1在高峰期的第3天)
         )    -- 连续三行记录
order by id;
```