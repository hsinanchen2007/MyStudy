### 解题思路
首先可以按照降序，进行排序，然后用limit n,x函数，跳过前n行，读取x行
不过可以进行判断一下是否查找为null。
### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N = N-1;
  RETURN (
      # Write your MySQL query statement below.
  
      select ifnull((
          select distinct
          Salary from Employee
          order by Salary desc
          limit N , 1
      ) ,null) as getNthHighestSalary
  );
END
```