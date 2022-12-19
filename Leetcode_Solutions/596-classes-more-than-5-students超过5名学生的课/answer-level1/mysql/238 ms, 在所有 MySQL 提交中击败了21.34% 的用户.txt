### 解题思路
第一步：
select class from courses group by class having count(class)>=5;
看上去视乎没有任何问题，但是当数据中同一个学生多个同样的课程时，题目要求时不计算在内，所以会导致与答案不匹配。

第二步：
所以我们过滤出一名学生只对应一个课的信息。
select distinct * from courses;

第三步：
结合一二步就可以得出答案
select class from (select distinct * from courses) as c group by class having count(student)>=5;


### 代码

```mysql
# Write your MySQL query statement below
select class from (select distinct * from courses) as c group by class having count(student)>=5;

```
