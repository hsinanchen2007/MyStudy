执行用时 :307 ms, 在所有 MySQL 提交中击败了83.70%的用户
```
select id,name from students
where id not in(
select s.id as id from departments as d inner join students as s on d.id= s.department_id
);
```
思路就是先连接两个表，找出院系有效的学生id。然后再从学生表里查出id不在有效范围内的学生id和姓名。