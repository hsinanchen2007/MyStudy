### 解题思路
"delete p1 from Person p1,Person p2"会将P1与P2组成一个笛卡尔集，当满足条件时，删除的时候P1中的数据。

### 代码

```mysql
delete p1 from Person p1,Person p2 where p1.Email=p2.Email and p1.Id>p2.Id;
```