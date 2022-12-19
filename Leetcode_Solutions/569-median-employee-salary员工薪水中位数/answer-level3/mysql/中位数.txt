#思路：
#（1）row_number排序 t3（2）计算每个公司人数总数 t4（3）t3连接t4,选择排名(t3.row_number=floor((t4.counts+1)/2) or t3.row_number=floor((t4.counts+2)/2))
select 
Id,t3.Company,Salary
from
(select
Id,Company,Salary,
case when @company<>Company then @row_number:=1 else @row_number:=@row_number+1 end row_number,
@company:=Company new_company 
from
(select  *
from Employee
order by Company,Salary asc limit 10000) t1,(select @row_number:=0,@company:=0)t2)t3,(select Company,count(*) counts from Employee group by Company)t4
where t3.Company=t4.Company
and (t3.row_number=floor((t4.counts+1)/2) 
or t3.row_number=floor((t4.counts+2)/2))