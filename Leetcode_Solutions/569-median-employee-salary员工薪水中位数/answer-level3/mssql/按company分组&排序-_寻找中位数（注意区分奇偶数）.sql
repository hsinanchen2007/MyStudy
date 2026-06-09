/* Write your T-SQL query statement below */
select Id,Company,Salary from
(select t1.Id,t1.Company,t1.Salary,
        case when t2.cc%2 = 1 then case when rn = (t2.cc+1)/2 then 1 else 0 end 
                              else case when (rn = t2.cc/2 or rn-1 = t2.cc/2) then 1 else 0 end end rrr from
(select *,row_number() over(partition by Company order by Salary) rn from Employee) t1
left join
(select Company,count(Company) cc from Employee group by Company) t2
on t1.Company = t2.Company) tt
where rrr = 1
