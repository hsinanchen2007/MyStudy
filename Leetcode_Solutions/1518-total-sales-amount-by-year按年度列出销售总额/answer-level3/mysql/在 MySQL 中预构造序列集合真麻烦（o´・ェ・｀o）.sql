根据题目，查询销售日期介于 2018 年至 2020 年之间，那么我们先构造符合销售条件的时间区间：

```sql
select '2018'             as report_year,
       date('2018-01-01') as start_date,
       date('2018-12-31') as end_date
from dual
union all
select '2019'             as year,
       date('2019-01-01') as start_date,
       date('2019-12-31') as end_date
from dual
union all
select '2020'             as year,
       date('2020-01-01') as start_date,
       date('2020-12-31') as end_date
from dual
```

得到：
| report\_year | start\_date | end\_date |
| :--- | :--- | :--- |
| 2018 | 2018-01-01 | 2018-12-31 |
| 2019 | 2019-01-01 | 2019-12-31 |
| 2020 | 2020-01-01 | 2020-12-31 |

将 Sales 表和上述时间区间表连接，注意销售区间和自然年存在三种关系：
1. 销售区间包含自然年的后半段
2. 销售区间包含自然年的前半段
3. 整个自然年都在销售区间之内

```sql
select t2.product_id,
       t3.product_name,
       t1.report_year,
       (datediff(
           if(t1.end_date<t2.period_end, t1.end_date, t2.period_end), # 结束时间取最小
           if(t1.start_date>t2.period_start,t1.start_date, t2.period_start) # 开始时间取最大
       )+1) * t2.average_daily_sales as total_amount
from (
         select '2018'             as report_year,
                date('2018-01-01') as start_date,
                date('2018-12-31') as end_date
         from dual
         union all
         select '2019'             as year,
                date('2019-01-01') as start_date,
                date('2019-12-31') as end_date
         from dual
         union all
         select '2020'             as year,
                date('2020-01-01') as start_date,
                date('2020-12-31') as end_date
         from dual
     ) t1,
     Sales t2,
     Product t3
where (
    # 销售区间包含自然年的后半段
    (t2.period_start between t1.start_date and t1.end_date)
    # 销售区间包含自然年的前半段
    or (t2.period_end between t1.start_date and t1.end_date)
    # 整个自然年都在销售区间之内
    or (t1.start_date > t2.period_start and t1.end_date <t2.period_end)
)
and t2.product_id = t3.product_id
order by product_id, report_year;
```

以上。