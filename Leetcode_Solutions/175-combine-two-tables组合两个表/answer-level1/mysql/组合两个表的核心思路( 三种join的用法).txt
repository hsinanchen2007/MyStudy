### 解题思路
此处撰写解题思路
    题目中要求：无论 person 是否有地址信息(varchar)，都需要基于上述两表提供 person 的以下信息。

    也就是说，无论Address是否有 City和State的属性(即使为null)
    都要其输出结果(有null值,则判定为附属表,通过另一个表作为标准)

    也就是要求为：Address表以Person表为标准(也就是Person中有的PersonId,在Address表中若该PersonId也存在,则输出该数据)
    即 select xxx from Person left join Address on 约束条件
    或者 select xxx from Address right join Person on 约束条件

    PS：不可以使用 select xxx from Address join Person on 约束条件
    因为：默认join为inner join，自动筛选掉null的元素


### 代码

```mysql
# Write your MySQL query statement below
Select FirstName,LastName,City,State
from Person left join Address
on Person.PersonId = Address.PersonId
```