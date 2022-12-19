### 解题思路
确定最值比较容易，通过已有的聚合函数加上group by便可轻松得到答案，但是找到最值所对应的元组信息是这个题的关键点，对此问题，我们的思路就是去给我们的最值“添加主键”。
我的代码的做法是首先保证了最值和departmentid之间可以达到一个唯一性的情况，然后用in去查询
同理，将子查询的结果作为一个新的表也可以达到效果
### 代码

```mysql
# Write your MySQL query statement below
select d.Name as Department, e.Name as Employee, salary
from Department d, Employee e
where d.id=e.departmentid and
(e.salary, e.departmentid) in
(select max(salary), departmentid
from employee
group by departmentid);
```