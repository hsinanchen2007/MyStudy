CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
     SELECT SALARY into result FROM ( select salary from (select distinct salary from employee order by salary desc) where rownum<=N minus  select salary from (select distinct salary from employee order by salary desc) where rownum<=N-1 ) ;

    RETURN result;
END;