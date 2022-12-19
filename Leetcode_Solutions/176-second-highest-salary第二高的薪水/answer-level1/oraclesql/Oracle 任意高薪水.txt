Oracle实现任意高薪水，当然任意低薪水也可参考实现。
```
select min(salary) SecondHighestSalary
from(select salary,row_number()over(order by salary desc) rn
    from(
         select distinct salary from Employee
        )
    )
where rn!=1 and rn<=2;
```
`rn!=1`是为了防止Table中只有一条数据。

执行用时 : 839 ms, 在Second Highest Salary的Oracle提交中击败了88.18% 的用户
内存消耗 : N/A