### 解题思路
此处撰写解题思路

### 代码

```mysql
#这里必须要做个笔记了
#之前写select distinct Salary from employee E1 where N=select count(*) 
# from Employee  E2  where E1.Salary <E2.Salary 
#有一个测试用例没通过，原因是， 当salary里面有重复值的时候，会出错比如(200,200,300)寻找第二高薪水，
#下面为改进
#将select * from employee group  by Salary作为临时表来查询，实现了salary的去重，然后再比。


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N=N-1;
     
    

  RETURN (
       select ifnull(
     (
select distinct Salary from employee  E1 where N=(select count(*) 
from (select * from employee group  by Salary
) as E2  where E1.Salary <E2.Salary)
),
      null
      ) 
      # Write your MySQL query statement below.
      
  );
END 
```