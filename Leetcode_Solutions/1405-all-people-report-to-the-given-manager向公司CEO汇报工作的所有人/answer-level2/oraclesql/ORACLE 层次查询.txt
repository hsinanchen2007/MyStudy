
要注意的是：employee_id等于1时manager_id也等于1，此时产生回环，所以要加上NOCYCLE
select distinct employee_id from employees
                    where level <=3 and level != 1
         start with manager_id = 1 connect by NOCYCLE prior employee_id = manager_id