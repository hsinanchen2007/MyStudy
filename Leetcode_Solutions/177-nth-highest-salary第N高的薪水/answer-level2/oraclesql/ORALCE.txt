CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    SELECT DECODE((SELECT salary
              
                FROM (SELECT salary, ROWNUM AS RN
                      
                        FROM (SELECT DISTINCT salary
                                FROM employee
                               ORDER BY salary DESC)
                      
                      )
               WHERE RN = N),
              NULL,
              NULL,
              (SELECT salary
               
                 FROM (SELECT salary, ROWNUM AS RN
                       
                         FROM (SELECT DISTINCT salary
                                 FROM employee
                                ORDER BY salary DESC)
                       
                       )
                WHERE RN = N)) into result
  FROM DUAL;
    RETURN result;
END;