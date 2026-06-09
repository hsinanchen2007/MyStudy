### 解题思路
两大步骤：
一、对employee 表进行排序，通过自关联的方式（employee A join employee B），根据部门进行各自部门（on A.departmentid = B.departmentid）的薪资排序，自己和自己比（A.salary <= B.salary），小于或等于自己的薪资的个数就是排在第几个位置，（例如：最大薪资，肯定只有自己是小于或者等于自己，所以排第一），所以选择前三位置的，也就是（count(distinct B.Salary)<=3），最后的order by 就是排下序
二、将以上新的表和另外的那个部门表department，进行id关联，把部门的名称匹配上去就完成了（最外层的表要根据题目要求，只选择需要的字段就可以了）
新手小白，不正之处，请大神们多多指正

### 代码

```mysql
# Write your MySQL query statement below
select E.name as Employee,E.salary as Salary,F.name as Department from (select A.*,count(distinct B.Salary)  from employee A join employee B
on A.departmentid = B.departmentid
and A.salary <= B.salary
group by A.id
having count(distinct B.Salary)<=3
order by departmentid asc ,count(distinct B.Salary) asc)E,
department F 
where E.departmentid = F.id 
 
```