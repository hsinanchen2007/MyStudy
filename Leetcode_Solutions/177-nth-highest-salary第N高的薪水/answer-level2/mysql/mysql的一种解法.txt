CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
	DECLARE page INT;
	SET page = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      **核心就是这里使用分页形式保存, 先反序数据, 每页保存1个, 第几页就是第几高,** ~反过来就是第几低~.
      1. 需要将将排名-1, 因为limit x, y从0开始; 
      2. 需要distinct去重(也是提交才发现的).
      select distinct(Salary) as SecondHighestSalary  from Employee order by Salary desc limit page, 1
  );
END