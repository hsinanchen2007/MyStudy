```
select 
    distinct 
        date_format(f.pay_date,'%Y-%m') as pay_month,
        f.department_id,
    case when de < am then 'lower'  
         when de > am then 'higher'
        else 'same'
    end as comparison  
from (
    select avg(amount) as am ,pay_date from  salary  group by  pay_date)t ,
    (select avg(s.amount) as de,pay_date, e.department_id from salary s left join employee e on e.employee_id=s.employee_id group by e.department_id,pay_date  )f
where t.pay_date=f.pay_date
order by  f.department_id,pay_month asc;
```
