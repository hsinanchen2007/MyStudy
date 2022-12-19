1.思路是交换student列
select id, 
case when id=c.count and id%2=1 then (select student from seat where id =c.count) 
when id%2=1 then (select student from seat where id = a.id+1)
else (select student from seat where id = a.id-1) end as  student
from seat a,
(select count(*) as count from seat) c

2.思路是交换Id列
select 
(case when Id%2!=0 AND Id!=counts then Id+1
 when Id%2!=0 AND Id=counts then Id
else Id-1 end) as Id,
student
from seat,(select count(*) as counts from seat) as count_seat
order by id asc

3.使用位运算异或，感觉不容易想到
SELECT
    s1.id,isnull(s2.student,s1.student) as student
FROM
    seat s1
        LEFT JOIN
    seat s2 ON (s1.id+1)^1-1 = s2.id
ORDER BY s1.id;