### 解题思路
此处撰写解题思路
先求出哪个经理ID下有五个及以上的下属，然后再找到对应的经理
### 代码

```mysql
# Write your MySQL query statement below

select Name
from Employee
where Id in
(select ManagerId from Employee group by ManagerID having count(name)>=5);
```