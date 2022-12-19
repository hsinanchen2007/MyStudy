### 解题思路

left join。
不知道怎么成绩这么差
执行用时 :361 ms, 在所有 MySQL 提交中击败了5.08% 的用户

### 代码

```mysql
# Write your MySQL query statement below
select E1.name,e2.bonus
from Employee e1  
left join  bonus   e2
on e1.empId = e2.empId
where bonus <1000 or bonus is null
```