思路：

这题我用到了sum() over(partition by ... order by ... rows ...)这个聚合窗口函数。

主要分为四步：

1、首先排除掉每个员工当前统计月份的薪水记录，也就是排除每个员工最大月份的薪水记录。

2、然后对剩下的薪水记录，按照员工Id分组，月份升序，对薪水Salary进行逐月累计求和，这样可以得到每个员工每个月（已除去当前月份）截止当月的累计薪水。

3、上一步获得的累计薪水还要加上一个限制条件：最近三个月。所以再加上rows子句，取当前月和前两个月的薪水累计，即可得到每个员工每个月最近三个月的累计薪水。

4、最后按照Id升序，Month降序排序就完成啦！
```
select Id,Month,sum(Salary) over(partition by Id order by Month rows between 2 preceding and 0 following) as Salary 
from (
    select Id,Month,Salary,
        row_number() over(partition by Id order by Month desc) as rn
    from Employee
) T
where rn<>1
order by Id,Month desc
```
执行用时 :802 ms, 内存消耗 :0B