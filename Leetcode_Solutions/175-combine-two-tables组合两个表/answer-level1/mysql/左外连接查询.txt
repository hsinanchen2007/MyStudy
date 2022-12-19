### 解题思路
address表和person表中分别以addressId和personId为主键，要求查出所有person的数据，所以就person当左表，用左外连接查询；反之亦然。

### 代码

```mysql
# Write your MySQL query statement below
select p.FirstName,p.LastName,a.City,a.State
from Person p
left join  Address a on
 p.PersonId=a.PersonId;

```