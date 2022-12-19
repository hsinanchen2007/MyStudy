如果有4个人工资分别为 300 200 200 100，那100就是第3高的而不是第4高的
CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
          select isnull((select top(1) Salary SecondHighestSalary from Employee a  where not exists(select * from (select distinct TOP(@N-1)Salary from  Employee order by Salary desc) b where a.Salary=b.Salary ) order by Salary desc),null)SecondHighestSalary
    );
END