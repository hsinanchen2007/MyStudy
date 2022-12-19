### 解题思路
多次in

### 代码

```mysql
# Write your MySQL query statement below
select employee_id 
from employees 
where 
    manager_id  in 
        (
        select employee_id 
        from employees 
        where 
            manager_id in 
            (
            select employee_id 
            from employees 
            where manager_id  in 
                (
                select employee_id 
                from employees
                WHERE manager_id = 1
                )  
            )
        ) 
    and employee_id !=1
    ```