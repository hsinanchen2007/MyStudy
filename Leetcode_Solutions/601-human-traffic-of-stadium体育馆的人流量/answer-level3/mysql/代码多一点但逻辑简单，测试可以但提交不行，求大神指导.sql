select distinct all_table.id id, all_table.visit_date visit_date, all_table.people people #@4去除重复项
from(
(select a.id id, a.visit_date visit_date, a.people people #@1表一，以三天为一个单位，选出第一天
from stadium a,stadium b, stadium c
where datediff(b.visit_date, a.visit_date)=1 and datediff(c.visit_date, b.visit_date)=1 and a.people>100 and b.people>100 and c.people>100  
union  #@3连接两张表
select c.id id, c.visit_date visit_date, c.people people #@2表二，以三天为单位，选出最后一天
from stadium a,stadium b, stadium c
where datediff(b.visit_date, a.visit_date)=1 and datediff(c.visit_date, b.visit_date)=1 and a.people>100 and b.people>100 and c.people>100) all_table);