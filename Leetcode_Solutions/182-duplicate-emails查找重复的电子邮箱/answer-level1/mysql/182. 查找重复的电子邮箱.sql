1. ```
# Write your MySQL query statement below
# ERROR: Every derived table must have its own alias 必须有别名
# select Table_Num.Email as Email

# from (
#   select Email, count(*) as Num
#   from Person
#   group by Email
# ) as Table_Num

# where Table_Num.Num != 1
```

2. group by + having
```
select Email
from Person
group by Email
having count(Email) > 1
```
