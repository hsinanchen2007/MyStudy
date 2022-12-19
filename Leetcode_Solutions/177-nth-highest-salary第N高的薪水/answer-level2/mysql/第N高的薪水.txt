### 解题思路

解题思路和第二高的思路是一样的，主要是判断当N为0时的不合理情况
### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    # 精简版
    DECLARE N1 INT DEFAULT N-1; 
    # 需先判断N为0时的不合理情况
    IF(N1 < 0) THEN
        RETURN NULL;
    ELSE 
        RETURN(
            select (select salary from employee group by salary desc limit N1,1) as secondHighestSalary
        );
    END IF;
END
```