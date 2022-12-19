审题环节：
看到俩表，那连接或者笛卡尔乘积跑不了了
查询的东西: `FirstName, LastName, City, State`

**关键说明：**
看到*无论 person 是否有地址信息*，就明白要用left join了，以左表为准

**SQL：**
```
select firstname, lastname, city, state
from person as p left join address as a on p.personid = a.personid
```
