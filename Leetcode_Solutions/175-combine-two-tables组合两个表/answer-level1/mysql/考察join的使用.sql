### 解题思路
此处撰写解题思路
1.条件中，无论 person 是否有地址信息，则表明，使用join时，那就是left join；如果使用笛卡尔积，应该加上where Address.key is null
2.主键：person表中personId是主键，那便不会产生重复；但是Address表中，AddressId是主键，那PersonId有可能会重复的，City和State也有可能重复，所以理论上应该进行去重

### 代码

```mysql
# Write your MySQL query statement below
select 
    FirstName
    ,LastName
    ,City
    ,State 
from 
(
    select 
        PersonId
        ,FirstName
        ,LastName
    from 
        Person 
) t1 
left join 
(
    select 
        PersonId
        ,City
        ,State
    from 
        Address
    group by
        PersonId
        ,City
        ,State 
) t2 
on 
    t1.PersonId = t2.PersonId
```