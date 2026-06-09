因为自己初学Oracle，看了好几个题解发现很少Oracle的，就尝试自己写，艰难地用rownum做出来了，给同样想要Oracle的朋友们一个解决方案。

```
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    SELECT NVL(Salary,NULL) INTO result
    FROM (SELECT ROWNUM num,Salary 
          FROM (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC)
          WHERE ROWNUM<=N 
          ORDER BY ROWNUM ASC)
    WHERE num=N;
    RETURN result;
END;
```
这是给了我很大帮助的介绍rownum使用的链接
[http://www.blogjava.net/freeman1984/archive/2011/01/20/343253.html]()