**思路**

刚审题，发现很简单，便直接使用 inner join ,以 personid 连接，提交发现错误；
再次查看要求，发现应该使用 left jion 来进行表关联。
总结：要注意 inner join 和 left join 的一些区别。
         inner join 是两张表都有的，一一相等的
         left join 是左表全部有

**代码**
select a.Firstname,a.Lastname,b.City,b.State from person a left join address b on a.personid=b.personid