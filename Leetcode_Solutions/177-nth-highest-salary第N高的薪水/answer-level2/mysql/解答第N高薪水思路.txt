### 解题思路

第N高的薪水，可以利用 limit x，y来解答
limit x,y 类似于 limit x offset y ，即跳过x行,取y行数据。

题中，输入N，即返回第N高的薪水，则
当 N < 0 时，返回最低工资。（经测试，默认是这样返回，其他的按需求返回即可）
当 N >= 1 时，则返回第N高工资

因为 limit x,y 函数的关系，跳过x行，取y行。故输入N的时候，需要先减去1才能取回第N高的薪水，否则会跳过第N高的薪水数据，取了第N+1高的薪水数据出来，所以代码如下

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  if N<0 then    
    RETURN (select min(Salary) from Employee);
  else   
    set N = N-1;
    RETURN (
        # Write your MySQL query statement below.
        select ifnull((select distinct Salary from Employee order by Salary desc limit N,1),null) as NthHighestSalay 
    );
  end if;
END
```