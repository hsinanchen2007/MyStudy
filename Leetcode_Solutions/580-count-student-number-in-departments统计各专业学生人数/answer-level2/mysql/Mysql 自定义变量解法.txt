```
select dept_name,student_number from (
    select 
        dept_name,student_number,
        @num := left(dept_name,max(len))  as num
    from 
    (select 
            d.dept_name ,count(student_id) as student_number ,length(d.dept_name) as len
    from student s  
    right join department d on d.dept_id= s.dept_id
    group by d.dept_id 
    order by student_number  desc
    )s ,
    (select @num:=0,@pre:=0)b  
    group by dept_name,len
    order by student_number desc,num  asc
)t;

```
