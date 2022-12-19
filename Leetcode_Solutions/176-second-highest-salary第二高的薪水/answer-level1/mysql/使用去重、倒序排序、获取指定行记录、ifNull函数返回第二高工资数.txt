### 解题思路
此处撰写解题思路
1.首先对工资进行去重、倒序排序。
2.再取出指定行的记录-这里为第二行。
3.最后使用ifNull函数返回第二高工资数，如第二高工资数不存在则返回null。
### 代码

```mysql
select
 ifNull(
     (select distinct salary
     from Employee order by Salary Desc
     limit 1,1),null
 ) as SecondHighestSalary;
```