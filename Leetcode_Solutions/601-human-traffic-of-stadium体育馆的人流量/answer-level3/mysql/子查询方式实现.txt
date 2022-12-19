### 解题思路
1.查询出满足条件的记录
2.分条件讨论（id、id+1、id+2在记录中；id-1，id-2，id-3在记录中；id-2，id-1，id在记录中）三种情况or连接作为条件

### 代码

```mysql
select id, visit_date, people
from stadium
where (id in (select id from stadium where people >= 100) and id + 1 in (select id from stadium where people >= 100) and
       id + 2 in (select id from stadium where people >= 100))
   or (id in (select id from stadium where people >= 100) and id + 1 in (select id from stadium where people >= 100) and
       id - 1 in (select id from stadium where people >= 100))
   or (id in (select id from stadium where people >= 100) and id - 1 in (select id from stadium where people >= 100) and
       id - 2 in (select id from stadium where people >= 100))
```