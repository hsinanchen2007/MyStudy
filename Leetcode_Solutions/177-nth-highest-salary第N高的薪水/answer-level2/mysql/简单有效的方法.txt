


```
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    declare p int;
    set p = N-1;
    set @a = (select Salary
    from (select distinct Salary
    from employee
    order by salary desc) as b limit 1 offset p);
  RETURN (
      # Write your MySQL query statement below.
    @a
  );
END;
```

