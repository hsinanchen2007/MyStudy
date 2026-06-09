# Write your MySQL query statement below
select 
    t1.pay_month as pay_month,
    t1.department_id as department_id,
    if(t1.a>t2.a,'higher',if(t1.a=t2.a,'same','lower')) as comparison
    from(
    select pay_month,department_id,avg(amount) as a from
            (select 
                id,
                s.employee_id as employee_id,
                amount,
                department_id,
                date_format(pay_date,'%Y-%m') as pay_month
            from salary s join employee e 
            on s.employee_id=e.employee_id) t
    group by pay_month,department_id) t1
left join(select pay_month,avg(amount) as a from
        (select 
            id,
            s.employee_id as employee_id,
            amount,
            department_id,
            date_format(pay_date,'%Y-%m') as pay_month
        from salary s join employee e 
        on s.employee_id=e.employee_id) t
    group by pay_month) t2
on t1.pay_month=t2.pay_month
order by department_id asc