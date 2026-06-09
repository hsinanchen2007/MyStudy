
关键：运用row_number()函数和ISNULL函数。
思路：考虑薪水可能有重复，先去重distinct; 然后对Salary进行排序（desc降序），接着采用row_number()对排序后Salary进行编号，最后查询编号为N的Salary，即第N高的薪水。null的问题可以通过isnull函数解决。

CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        select ISNULL(Salary,null) from 
        (select ROW_NUMBER() over(order by tmp.Salary desc) as nums, tmp.Salary from (select distinct salary from Employee) as tmp) 
        as tmpSalary where tmpSalary.nums= @N )
END