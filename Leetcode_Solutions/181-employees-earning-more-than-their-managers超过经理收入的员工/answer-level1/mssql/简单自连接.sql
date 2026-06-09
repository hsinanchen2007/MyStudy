如何能够知道雇员的经理是谁，需要两张表从雇员表得到经理编号然后遍历经理表id，但是这里只有一张表，所以使用自连接分成了两张表进行查询
/* Write your T-SQL query statement below */
SELECT S1.Name AS Employee
FROM Employee S1 JOIN Employee S2
ON S1.ManagerId = S2.Id
WHERE S1.Salary > S2.Salary