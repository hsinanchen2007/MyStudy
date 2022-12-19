### 解题思路
此处撰写解题思路

### 代码

```mssql
/* Write your T-SQL query statement below */
select Email from Person
group by Email
having count(Email)>1 
```