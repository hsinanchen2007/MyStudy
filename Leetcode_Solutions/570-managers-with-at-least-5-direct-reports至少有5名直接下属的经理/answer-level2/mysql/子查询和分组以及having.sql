### 解题思路
闲言碎语不要讲，直接看sql就妥了
### 代码

```mysql
# Write your MySQL query statement below
select `Name` from Employee where id in (select ManagerId from Employee group by ManagerId having count(*) >= 5);
```