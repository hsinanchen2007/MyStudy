MySql下比较好写，MsSql只写出个这样蹩脚的答案，速度还行，超过了79%的人：
```
CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    declare @result as int
    declare @dc as int
    --dc指DistinctCount
    select @dc=(select count(distinct Salary) from Employee)
    if(@N<=0 or @N>@dc)
        select @result=null
    ELSE
        select @result=(
            Select min(Salary) from [Employee]
            where Salary in
                (Select distinct top(@N) Salary
                 from [Employee]
                 order by Salary DESC)
        )
    RETURN (
        @result
    );
END
```
