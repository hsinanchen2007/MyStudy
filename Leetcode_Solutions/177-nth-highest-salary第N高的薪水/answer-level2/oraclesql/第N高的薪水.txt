### 解题思路
1.排序
2.获取值

### 代码

```oraclesql
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) 
RETURN NUMBER 
IS
result NUMBER;
BEGIN
     select  nvl(
          (select distinct b.Salary  from (
select a.*, dense_rank() over(order by a.Salary   desc) as rn
                     from Employee  a ) b where b.rn =N),null ) into  result from dual;
    
    RETURN result;
END;
```