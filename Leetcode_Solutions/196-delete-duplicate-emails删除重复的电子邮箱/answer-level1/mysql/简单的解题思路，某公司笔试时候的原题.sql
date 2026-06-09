### 解题思路
很经典的笔试题
### 代码

```mysql
# Write your MySQL query statement below
delete from Person 
where 
id not in  
(
    select id
    from
    (select min(id) id from Person group by Email)t



)

```