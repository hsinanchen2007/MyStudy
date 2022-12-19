题目对我来说还挺绕的
主要是*如果不存在第二高的薪水，那么查询应返回 null。*这一部分
至于第二薪水，用limit就好了

要从null这里着手，如何让为空的记录显示出null来
1. ifnull
2. 用子查询做一个虚拟临时表出来
但是核心都在于，所有的内容在初始的select里完成，
因为我们所得到的是一张只有一列的表，列的名称是 SecondHighestSalary

个人认为想明白这个事情是比较重要的，大部分常规思路都围绕此展开

**先写第二高薪水的查询**
```
select distinct salary
from employee
order by salary desc limit 1, 1
```
**方法一：子查询嵌套**
```
select
(select distinct salary
from employee
order by salary desc limit 1, 1) as SecondHighestSalary; 
```

**方法二：使用ifnull**
```
select ifnull(
(select distinct salary
from employee
order by salary desc limit 1, 1), null) as SecondHighestSalary;
```
这两种方法其实内核是一样的，使用了相同的“取第二高”方法，即排序之后limit，只是对null的出现用了些许不同的方法
----
一些其他“取第二高”的思路：

1. 第二高，把salary中的第一高去掉，剩下的最大就是第二高
`select max(salary) from employee where salary <> (select max(salary) from employee)`
   这个方法的好处可能是不需要考虑distinct的情况，因为max聚合之后自动消除了重复


其他应该也有，不浪费时间想了