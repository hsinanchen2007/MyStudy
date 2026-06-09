### 解题思路
此处撰写解题思路
group by分组， 查询条件count(email)>1筛选重复字段
### 代码

```mssql
select email from Person  group by email
having count(email)>1

```