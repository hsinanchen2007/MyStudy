### 解题思路

先按照Salary进行排序，再输出序号为N的Salary
### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select t2.Salary  from (select t.*,@i:=@i+1 as rank from (select distinct Salary from Employee order by Salary desc) as t,(select @i:=0) r) t2 where t2.rank = N 
  );
END
```