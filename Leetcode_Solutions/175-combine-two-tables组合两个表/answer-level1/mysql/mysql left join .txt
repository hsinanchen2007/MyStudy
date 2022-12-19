### 解题思路

编写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：


此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a276c8b5d0474cddf848d8678cc4891ed133992445ad4218ee0b0c3edd2e48fb-image.png)

### 代码

```mysql
# Write your MySQL query statement below

select p.FirstName, p.LastName,t.City,t.State
from Person p left join Address t
on p.PersonId = t.PersonId
```