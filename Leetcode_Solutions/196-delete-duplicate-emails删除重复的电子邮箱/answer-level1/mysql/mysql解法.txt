# Write your MySQL query statement below
# mysql不能同时查询和删除同一张表，所以要用子查询包装一下欺骗mysql...
delete
from person
where id not in (
    select id from (
        (select id 
        from person a
        where id = 
            (select id from person b where b.email = a.email order by id limit 1)
        )t
    )
)