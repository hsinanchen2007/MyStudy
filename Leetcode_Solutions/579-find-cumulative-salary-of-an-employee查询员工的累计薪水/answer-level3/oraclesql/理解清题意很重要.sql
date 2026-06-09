```
-- 理解题意
-- 1. 每个月的sum_salary都是当前月实际薪水和前两个月实际薪水的和
-- 2. 题目并没有要求只显示除最近一个月以外的三个月，而是除最近一个月的所有月

select Id, Month, sum_salary Salary
from
(
    select Id, Month, 
    sum(Salary) over(partition by Id order by Month desc rows between 0 preceding and 2 following) sum_salary,
    row_number() over(partition by Id order by Month desc) rn
    from Employee
)
where rn <> 1;

-- 一开始我理解错了题意。求和方式每个月都是第一个月开始的累和，然后除去最近月的记录，限制显示三条记录
-- 搞错了方向，纠错花了不少时间
```
