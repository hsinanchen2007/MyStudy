```
#	165~183 ms
select e1.Id,
       e1.Company,
       e1.Salary
  from (
    select (@i:=(@i 
             +(@pre1 =(@pre1:=Company)) #公司没变，排序加1
             -((@pre2 <>(@pre2:=Company))*@i) #公司变了，排序重置
            )) + 1 as num,
           Id,
           Company,
           Salary
      from Employee,(select @i:=0,  @pre1:=-1, @pre2:=-1) t
     order by Company,Salary
  ) as e1,
  (
    select count(1)/2 as mid_num,
           Company  
      from Employee
     group by Company
  ) as e2
  where e1.Company = e2.Company
    and (e1.num = e2.mid_num or e1.num = e2.mid_num+0.5 or e1.num = e2.mid_num+1)
```
