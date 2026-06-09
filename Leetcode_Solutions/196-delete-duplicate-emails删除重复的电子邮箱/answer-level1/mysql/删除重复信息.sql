
# 来删除(删除!!!) Person 表中所有重复的电子邮箱

delete from person 
where id not in 
(select id from (select min(id) as id from person group by email ) as a);

思路：
1.将person表按email分组 group by Email
2.从上表读取最小Id值 min(id) ， 再将该表取别名为表a
3.删除person表中id值不为a表中id值的信息

原先写的是
delete from person where id not in (select min(id) as id from person group by email ) ;
但是会报 You can't specify target table 'person' for update in FROM clause 的错误。

解决方法：select的结果再通过一个中间表select多一次，就可以避免这个错误

