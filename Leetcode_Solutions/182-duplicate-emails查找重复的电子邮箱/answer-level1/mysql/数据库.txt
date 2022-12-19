### 解题思路


### 代码

```mysql
# Write your MySQL query statement below
Select distinct p1.Email from Person p1, Person p2 where p1.Email = p2.Email and p1.id <> p2.id;
```