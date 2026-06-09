select a.Email from 
(
select count(*) cnt, Email from Person group by Email 
) a
where a.cnt>1
