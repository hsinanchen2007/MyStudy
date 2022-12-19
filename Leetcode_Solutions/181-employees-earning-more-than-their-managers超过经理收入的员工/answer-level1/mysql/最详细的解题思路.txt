### 解题思路
1、select  ManagerId  from Employee  查询到所有的经理的id，得到临时结果集1
2、select id , Salary  from  Employee where id in (select  ManagerId  from Employee )  
   使用临时结果集1去查询到所有经理的收入和id，得到临时结果集2
3、此时Employee表和临时结果集2存在外键关系，所以此时就可以通过外键关联查询出最终的结果集。

### 代码

```mysql
select a.Name as Employee   from Employee a , (select id , Salary  from  Employee where id in (select  ManagerId  from Employee ) )b 
where a.ManagerId  = b.id and a.Salary > b.Salary 
```