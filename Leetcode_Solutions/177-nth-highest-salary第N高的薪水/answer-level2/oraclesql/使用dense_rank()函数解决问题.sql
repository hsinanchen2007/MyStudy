
```oracle[]
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    --distinct是为了避免返回的是多值
    select distinct(salary) into result
    from (select salary,dense_rank() over(order by salary desc) rank_ from employee) tmp
    where tmp.rank_=N;
    RETURN result;
END;
```
