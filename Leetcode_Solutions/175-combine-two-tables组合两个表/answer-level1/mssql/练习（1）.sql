### 解题思路
将要查询的列列出来。查询的主表写在前面。因为必须返回Person表，则要左联查询。然后做主键限定。

### 代码

```mssql
/* Write your T-SQL query statement below */
select Person.FirstName,Person.LastName,Address.City,Address.State  from Person
left JOIN Address
ON Person.PersonId = Address.PersonId;  

```