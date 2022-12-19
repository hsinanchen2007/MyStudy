第一种，max()方式查询

`select max(Salary) as SecondHighestSalary from Employee where Salary <(select max(Salary) from Employee order by Salary desc);`

理解如下，找第二大的薪资，通过where条件 查询Salary小于 子查询中的最大薪资语句可以实现目的。

但是不利于后期扩展。

例如，找第三大或第四大的时候，就得在 where条件中嵌套更多子查询，不利于维护

第二种，ifnull 方式查询

`select ifnull((select distinct Salary from Employee order by Salary desc limit 1,1),null) as SecondHighestSalary;`

理解如下，找第二大薪资，通过 ifnull(x,y) 函数判断x是否有值，有值则返回，没有则返回y。

`select distinct Salary from Employee order by Salary desc limit 1,1`
该子查询语句先排序在去重，利用分页的思想，一页一条数据，找到对应的值。
按题意返回null，结合 ifnull 函数即可达到目的。而且长远来看，相对于第一种也利于扩展维护。

备注：（limit x,y 跳过x条数据，取y条数据）。


以上就是两种的方式的考虑和理解。