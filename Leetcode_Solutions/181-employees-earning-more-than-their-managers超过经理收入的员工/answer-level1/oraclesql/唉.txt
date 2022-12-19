### 解题思路
此处撰写解题思路
### 代码
这个实在没啥分享的，就是通过不易，给个666，有更好的方法集美胸弟麻烦私信告诉我！
```oraclesql
/* Write your PL/SQL query statement below */
select a.name as Employee from Employee a join Employee b on a.managerid=b.id and a.salary>b.salary;
```