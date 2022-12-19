窗口函数解法：
```
select
    pay_month,
    department_id,
    (case when m_d_amount>company_amount then 'higher' when m_d_amount<company_amount then 'lower' else 'same' end) as comparison
from
(
    select 
    pay_month,
    department_id,
    avg(amount) over(partition by pay_month,department_id) as m_d_amount,
    avg(amount) over(partition by pay_month) as company_amount
    from 
    (
    select
        e.department_id,
        s.amount,
        CONVERT(varchar(7), pay_date, 120) as pay_month
    from employee e, salary s
    where e.employee_id=s.employee_id
    ) tmp
) a
group by pay_month, department_id, m_d_amount, company_amount
order by department_id
```
