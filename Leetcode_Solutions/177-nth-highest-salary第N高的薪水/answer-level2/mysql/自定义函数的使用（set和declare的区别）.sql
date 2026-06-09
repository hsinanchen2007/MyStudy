### 解题思路
此处撰写解题思路

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set n = N-1;
  RETURN (
      # Write your MySQL query statement below.
    select 
        if(count(Salary)> 0 ,Salary,null) 
    from 
    (
        select
            Salary
        from 
            Employee 
        group by 
            Salary
        order by 
            Salary desc
        limit n,1
    ) t
  );
END
```