[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
员工表自连接，关联id和managerid，并按经理group by分组，然后过滤掉下属少于5人的行。
```
select E1.Name
from Employee as E1 join Employee as E2 on(E1.id = E2.managerid)
group by E1.id,E1.Name
having count(E1.id) >= 5
```

# 解法二
员工表按经理group by分组， 过滤掉下属少于5人的经理。再连接员工表取出姓名。
```
select E.Name
from Employee as E
join 
(
    select ManagerId
    from Employee
    group by ManagerId
    having count(Id)>=5
) as A
on (E.Id = A.ManagerId)
```