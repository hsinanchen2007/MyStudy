### 解题思路
在使用left jion时，on和where条件的区别如下：

1、on条件是在生成临时表时使用的条件，它不管on中的条件是否为真，都会返回左边表中的记录。（右连接是同类型的）

2、where条件是在临时表生成好后，再对临时表进行过滤的条件，left join在条件不为真时候就全部过滤掉。

### 代码

```mysql
# Write your MySQL query statement below
select FirstName,LastName,City,State
from Person Left join Address
on Person.PersonId = Address.PersonId
;

```