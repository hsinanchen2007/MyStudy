/* Write your PL/SQL query statement below */
```
-- select department,employee,salary
-- from(
--     select d.name as department,e.name as employee,e.salary,
--            dense_rank() over(partition by d.id order by e.salary desc) rn
--      from employee e,department d
--      where 1 = 1
--        and e.departmentid = d.id
--      ) t   
-- where 1 = 1
--   and t.rn = 1;
-- ;




select d.name as department,e.name as employee,e.salary       
 from employee e,department d
 where 1 = 1   
   and e.departmentid = d.id
   and (e.departmentid,e.salary) in (select e1.departmentid, max(e1.salary) from employee e1 group by e1.departmentid)   
; 
```
