根据问题描述最近三个月的累计的计算方式为：
- 3月需要累加 3月、2月、1月的薪水
- 2月需要累加 2月、1月的薪水
- 1月需要累加 1月的薪水

表示成一个表格就是：
| Id | 聚合的 Month | 累加薪水的 Month| 
|----|-------------|---------------|
| 1  | 3           | 3             |
| 1  | 3           | 2             |
| 1  | 3           | 1             |
| 1  | 2           | 2             |
| 1  | 2           | 1             |
| 1  | 1           | 1             |

很容易得出笛卡尔积的限制条件：
```sql
select t1.Id, t1.Month, t2.Salary
from Employee t1,
     Employee t2
where t1.Id = t2.Id
  and t1.Month - t2.Month between 0 and 2
```

然后过滤掉每组最大的月份：
```sql
select t1.Id, t1.Month, t2.Salary
from Employee t1,
     Employee t2,
     (
         select Id, max(Month) as max_month
         from Employee
         group by Id
     ) t3
where t1.Id = t2.Id
  and t1.Month - t2.Month between 0 and 2
  and t1.Id = t3.Id
  and t1.Month != t3.max_month
```

最后根据条件聚合：
```sql
select t1.Id, t1.Month, sum(Salary) as Salary
from (
         select t1.Id, t1.Month, t2.Salary
         from Employee t1,
              Employee t2,
              (
                  select Id, max(Month) as max_month
                  from Employee
                  group by Id
              ) t3
         where t1.Id = t2.Id
           and t1.Month - t2.Month between 0 and 2
           and t1.Id = t3.Id
           and t1.Month != t3.max_month
     ) t1
group by t1.Id, t1.Month
order by Id, Month desc
```