CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    SELECT  SecondHighestSalary into result from (
   SELECT salary as SecondHighestSalary 

  FROM (SELECT salary, ROWNUM AS RN
        
          FROM (SELECT DISTINCT salary
                  FROM employee
                 ORDER BY salary DESC))
 WHERE RN = N
UNION
SELECT NULL AS SecondHighestSalary 
  FROM DUAL
 WHERE NOT EXISTS (SELECT salary
        
          FROM (SELECT salary, ROWNUM AS RN
                
                  FROM (SELECT DISTINCT salary
                          FROM employee
                         ORDER BY salary DESC))
         WHERE RN = N)

    );
    RETURN result;
END;