select s.id,s.visit_date,s.people from stadium s 
left join stadium s1 on  datediff(s.visit_date,s1.visit_date) = 2
left join stadium s2 on  datediff(s.visit_date,s2.visit_date) = 1
left join stadium s3 on  datediff(s.visit_date,s3.visit_date) = -1
left join stadium s4 on  datediff(s.visit_date,s1.visit_date) = -2
where s.people >= 100 and ((s1.people>=100 and s2.people>=100) or (s2.people>=100 and s3.people>=100) or (s3.people>= 100 and s4.people>=100));

select s.id,s.visit_date,s.people from stadium s 
left join stadium s1 on s.id = s1.id+2
left join stadium s2 on s.id = s2.id+1
left join stadium s3 on s.id = s3.id-1
left join stadium s4 on s.id = s4.id-2
where s.people >= 100 and ((s1.people>=100 and s2.people>=100) or (s2.people>=100 and s3.people>=100) or (s3.people>= 100 and s4.people>=100))


