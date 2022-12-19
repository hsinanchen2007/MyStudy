无论是否有address，都要有person的信息，考虑outer join

代码：
```
select person.firstname, person.lastname, address.city, address.state
from person left outer join address
on person.personid = address.personid
```
