### 解题思路
先考虑使用笛卡尔全集展开集合,根据题目要求,投影出需查询的列,再建立2表连接;处理笛卡尔过滤的思路可参考n-1法则

### 代码

```mysql
# Write your MySQL query statement below

select p.FirstName,p.LastName,a.City,a.State from Person p
left join Address a on p.PersonId = a.PersonId
```