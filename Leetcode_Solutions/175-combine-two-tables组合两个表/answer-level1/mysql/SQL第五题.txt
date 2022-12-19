```
select firstname, lastname, city, state
from person
left join address
on person.personid=address.personid;
```
left join 可以完美解决题目中提到的address为空时候的处理，
但是如果写成full join 会报错，不太明白为什么，求大神指点。