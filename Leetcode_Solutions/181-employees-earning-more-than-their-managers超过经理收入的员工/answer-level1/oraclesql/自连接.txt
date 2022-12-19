### 解题思路
这里有内连接以及直接使用Where的方式

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
Select m.Name as Employee From Employee e join Employee m on e.Id=m.ManagerId Where e.salary<m.salary

```