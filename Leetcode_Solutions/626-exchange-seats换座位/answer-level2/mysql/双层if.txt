
id为偶数的学生id-1，为奇数时判断一下是不是最后一个
```
select if(id%2=0,id-1,if((select count(*)from seat)!=id,id+1,id)) as id,student
from seat
order by id
```
