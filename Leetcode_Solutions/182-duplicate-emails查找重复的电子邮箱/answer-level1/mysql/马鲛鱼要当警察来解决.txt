### 解题思路
此处撰写解题思路
Oraclesql：
mysql：select email from Person group by email having count(*)>1;
顺序：where>group by>having>order by
1.select email,count(*) from Person group by email-----先按照email分组
2.select email,count(*) from Person group by email having count(*)>1-------分组数量不唯一的就是重复的

```oraclesql
/* Write your PL/SQL query statement below */
select Email  from (select Email,count(*) from Person group by Email having count(*)>1);

```