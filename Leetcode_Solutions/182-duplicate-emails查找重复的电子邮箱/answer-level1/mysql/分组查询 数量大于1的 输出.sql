### 解题思路
分组查询 数量大于1的 输出

### 代码

```mysql
# Write your MySQL query statement below
select Email from Person 
group by Email having count(Email) > 1

```