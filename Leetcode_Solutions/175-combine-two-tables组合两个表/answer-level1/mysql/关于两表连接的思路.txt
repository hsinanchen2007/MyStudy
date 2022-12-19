### 解题思路
题目的要求是无论是否有地址的数据，都需要基于两表提供person的信息，而city和state字段则是属于Address表的，
地址允许为null，所有采用左外连接进行操作，将两表关联的共有字段就是PersonId，在连接过程中，使得Person.PersonId=Address.PersonId即可
### 代码

```mysql
select p.FirstName,p.LastName,a.City,a.State 
from person p left join address a 
on p.PersonId=a.PersonId;
