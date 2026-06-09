### 解题思路
这里直接用了offset偏移量来解题：
按工资降序显示出第二高的值，否则返回null

然后我从网上学习了limit的各类用法，在这里贴出来自己做个笔记。

使用查询语句返回前几条或者中间某几行数据：
SELECT * FROM table LIMIT [offset,] rows | rows OFFSET offset

LIMIT 子句可以被用于强制 SELECT 语句返回指定的记录数。LIMIT 接受一个或两个数字参数。参数必须是一个整数常量。如果给定两个参数，第一个参数指定第一个返回记录行的偏移量，第二个参数指定返回记录行的最大数目。初始记录行的偏移量是 0(而不是 1)： 为了与 PostgreSQL 兼容，MySQL 也支持句法： LIMIT # OFFSET #。

mysql> SELECT * FROM table LIMIT 5,10; // 检索记录行 6-15

//为了检索从某一个偏移量到记录集的结束所有的记录行，可以指定第二个参数为 -1： 
mysql> SELECT * FROM table LIMIT 95,-1; // 检索记录行 96-last.

//如果只给定一个参数，它表示返回最大的记录行数目： 
mysql> SELECT * FROM table LIMIT 5; //检索前 5 个记录行

//换句话说，LIMIT n 等价于 LIMIT 0,n。


### 代码

```mysql
# Write your MySQL query statement below
select ifnull(
    (select distinct Salary
    from Employee
    order by Salary desc
    limit 1
    offset 1),null) as SecondHighestSalary;
```