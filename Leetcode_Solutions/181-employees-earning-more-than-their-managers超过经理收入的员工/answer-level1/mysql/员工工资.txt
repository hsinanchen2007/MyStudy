### 解题思路
1.首先要确认员工和经理的区别，经理的话是没有对应的managerid
2.内联员工表 找到员工对应的经理
3.工资对比 获得结果

### 代码

```mysql
# Write your MySQL query statement below

select tt.Name as Employee from (select  * from Employee where ManagerId is not null )tt
inner join Employee ee
on tt.ManagerId=ee.Id 
where tt.Salary>ee.Salary

```