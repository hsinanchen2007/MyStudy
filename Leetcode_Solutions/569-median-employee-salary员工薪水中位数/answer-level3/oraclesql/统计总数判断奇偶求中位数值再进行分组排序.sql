### 解题思路
此处撰写解题思路

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
select t.Id,t.Company,t.Salary
  from (select Id,
               Company,
               Salary,
               row_number() over(partition by Company order by Salary asc) as rn
          from Employee
         order by Company asc, Salary asc) t
 inner join (select Company,
                    round(count(id) / 2) as n_right,
                    case  when mod(count(id), 2) = 1 then  1 else  0  end as flag
               from Employee
              group by Company)  s
on (t.Company=s.Company)  
and ( (t.rn=s.n_right and s.flag=1)
       or 
       ((t.rn=s.n_right  or  t.rn=s.n_right+1) and s.flag=0)
    )
order by Company asc,Salary asc ,Id asc



  






```