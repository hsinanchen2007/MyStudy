### 解题思路
明确题目的要求，题目是从原始表格中直接删除重复的电子邮箱，只保留id最小的那个。
要删除表中的数据，需要使用delete from;
删除语句：delete from table_name where (要删除数据的条件)
方法一：
1.根据email分组，筛选出每个不同email的最小id值：
select min(id) as id from person group by email
2.将最小的id提取出来
select temp.id from
(select min(id) as id from person group by email) as temp
3.删除id较大的重复的电子邮箱删除
delete from person
where person id not in
(select temp.id from
(select min(id) as id from person group by email) as temp
);
方法二：
复用person表。p1,p2将其数据进行对比比较
如果p1.email=p2.email,且满足p1.id>p2.id则把p1对应的数据删除，保留p2对应的数据
1.选出表格中id较大的重复的电子邮箱
select p1.* from person p1,person p2
where p1.email>p2.email
and p1.id>p2.id
2.把第一步中选出的邮箱删除
delete p1 from person p1,person p2
where p1.email=p2.email
and p1.id>p2.id

### 代码

```mysql
# Write your MySQL query statement below
delete from person
where id not in
(select temp.id from 
(select min(id) as id from person group by email) temp);

```