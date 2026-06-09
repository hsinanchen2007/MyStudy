因为mssql没有limit方法，第一次通过取最大值再排除最大值的方法取到第二高值。
后来看他人解体思路，提到取任意第几高值，所以多次尝试后，终于找到第二解决方案，可以实现取任意第几高值。
思路：
先通过group by语句排除重复值，然后通过row_number() 函数对薪资从高到低排序，然后把这次查询结果做为表A，
对表A再次查询，需要查第几高值，便指定行数几。
包了一层max()函数，是因为行数不存在时，mssql返回空值，但使用max()函数便能返回null值。目前未找到其他能将空行转换为null值的函数。

另外，本题需要注意字段重命名。

select max(Salary) as SecondHighestSalary
from (
    select Salary, row_number() over (order by Salary desc) as num
    from employee b
    group by Salary
) a
where a.num = 2
