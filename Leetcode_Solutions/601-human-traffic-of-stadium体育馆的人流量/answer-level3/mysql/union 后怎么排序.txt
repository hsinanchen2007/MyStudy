select s1.id,s1.visit_date,s1.people
FROM stadium s1,  stadium s2, stadium s3
WHERE (s2.id=s1.id+1 and s3.id = s2.id+1) and (s1.people >=100 and s2.people >=100 and s3.people>=100)
union
select s2.id,s2.visit_date,s2.people
FROM stadium s1,  stadium s2, stadium s3
WHERE (s2.id=s1.id+1 and s3.id = s2.id+1) and (s1.people >=100 and s2.people >=100 and s3.people>=100)
union
select s3.id,s3.visit_date,s3.people
FROM stadium s1,  stadium s2, stadium s3
WHERE (s2.id=s1.id+1 and s3.id = s2.id+1) and (s1.people >=100 and s2.people >=100 and s3.people>=100)

问下，该怎么排序