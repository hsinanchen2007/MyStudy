### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
delete p1 from Person p1, Person p2 where p1.Email = p2.Email and p1.Id > p2.Id
```