```
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set n = N-1; # 第N高的，设置便宜为N-1，例如第2高的,偏移offset=1, limit 1,1  ,第一个1是offset的位置
  RETURN (
      # Write your MySQL query statement below.
      # 若果数据不存在，输出null，用ifnull(数据,null)
      select ifnull ((select distinct Salary from Employee order by Salary desc limit n,1),null) as getNthHighestSalary
  );
END
```

