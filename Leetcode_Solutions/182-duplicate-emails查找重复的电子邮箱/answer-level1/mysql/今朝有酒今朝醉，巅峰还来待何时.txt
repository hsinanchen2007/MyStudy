### 解题思路
利用聚合函数对其以Email字段分类的表，统计其数量，最后选择大于1的返回结果便是
### 代码

```mysql
# Write your MySQL query statement below
select Email from (
    select Email , count(Email) as num from Person group by Email
) as statisc where num > 1;
-- select Email from
-- (
--   select Email, count(Email) as num
--   from Person
--   group by Email
-- ) as statistic
-- where num > 1
-- ;

```