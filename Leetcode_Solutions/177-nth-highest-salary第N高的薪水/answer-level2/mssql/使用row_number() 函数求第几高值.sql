因为mssql没有limit方法，所以使用row_number() 函数。
思路：
先通过group by语句排除重复值，然后通过row_number() 函数对薪资从高到低排序，然后把这次查询结果做为表A，
对表A再次查询，需要查第几高值，便指定行数几。
包了一层max()函数，是因为行数不存在时，mssql返回空值，但使用max()函数便能返回null值。目前未找到其他能将空行转换为null值的函数。
因为和176题很相似，第一次提交时忘记改参数了｜｜｜

CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    RETURN (
        /* Write your T-SQL query statement below. */
        select max(Salary) as SecondHighestSalary
        from (
            select Salary, row_number() over (order by Salary desc) as num
            from employee b
            group by Salary
        ) a
        where a.num = @N
        
    );
END