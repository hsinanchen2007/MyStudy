执行用时 296 ms，超过 99%

参考了 @kaiker 的解答

1. 按 company 分组排序，记为 `rk`
2. 计算各 company 的记录数除以2，记为 `cnt`
3. 连接结果
4. 找出符合中位数要求的记录

有 2 个要点：
1. 分组排序通过两个变量完成，注意 @com 的更新顺序要在 @rk 之后
2. 按示例，若记录数为奇数，取一条，否则取两条，如记录数为7，则第4名是中位数，记录数为6，则第3，4名是中位数。由于 cnt = 计数除以2，则对应序号可直接用 `in (cnt+0.5,cnt+1,cnt)` 来表达

```
select b.id,b.company,b.salary
-- 3. 连接结果
from (
    -- 1. 按 company 分组排序，记为 `rk`
    select id,company,salary,
    case @com when company then @rk:=@rk+1 else @rk:=1 end rk,
    @com:=company
    from employee,(select @rk:=0, @com:='') a
    order by company,salary) b
left join 
    (-- 2. 计算各 company 的记录数除以2，记为 `cnt`
    select company,count(1)/2 cnt from employee group by company) c
on b.company=c.company
-- 4. 找出符合中位数要求的记录
where b.rk in (cnt+0.5,cnt+1,cnt);
-- 觉得有用请不吝点个赞哟
