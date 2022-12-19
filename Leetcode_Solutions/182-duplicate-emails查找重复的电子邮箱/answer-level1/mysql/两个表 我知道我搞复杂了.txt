select distinct a.Email from 
Person a, Person b 
where a.Id!=b.Id and a.Email=b.Email;