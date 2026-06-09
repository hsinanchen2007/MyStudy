这个题要考虑几个情况：
第一种为正常情况，所有工资不相等
select Salary as SecondHighestSalary from Employee  Order by Salary Desc limit 1,1;

第二种为无第二高工资情况，也就是只有一条记录
select  ifnull((select Salary as SecondHighestSalary from Employee  Order by Salary Desc limit 1,1),null) as SecondHighestSalary ;
在原有的基础上考虑null值，如果为空，将null赋值为第二高工资，有就直接复制

第三种为并列第一工资情况，多个相同工资排第一
select  ifnull((select Salary as SecondHighestSalary from Employee group by Salary Order by Salary Desc limit 1,1),null) as SecondHighestSalary ;
在查询之前先根据工资进行分组，然后排序，取第二个，为空则赋值为null

这样就解决了这个问题