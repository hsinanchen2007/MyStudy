思路：
1. **将薪水去重并倒序排列**
```
select distinct(Salary) from Employee order by Salary desc;
```
2. **为排序后的薪水添加行号rownum**
```
select t.Salary,rownum rm 
from (select distinct(Salary) from Employee order by Salary desc) t
where rownum <= N  
--添加rownum <= N,加快查询效率，只保留前N高的薪水记录(注意此时只能用rownum<=N,Oracle中rownum使用时必须包含小于号才有效)
```
3. **查询行号rownum=N的薪水-第N高薪水**
```
select max(t.Salary) 
from (select Salary
             ,rownum rm 
      from (select distinct Salary from Employee order by Salary desc)
      where rownum <= N) t
where t.rm = N;
```


完整代码如下：
```
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    select max(t.Salary)  into result
        from (select Salary,rownum rm 
             from (select distinct Salary from Employee order by Salary desc)
             where rownum <= N)t
    where t.rm = N; 
    RETURN result;
END;
```
