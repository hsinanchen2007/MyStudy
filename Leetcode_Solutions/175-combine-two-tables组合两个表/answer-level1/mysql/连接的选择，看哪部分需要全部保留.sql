### 多表查询，连接。
左连接，右连接，内连接。
![image.png](https://pic.leetcode-cn.com/05243a26fe4b8d463211c1a8464c7a10da403eac27241345d00f10ba3d3be75f-image.png)
部分选择

### 代码

```mysql
# Write your MySQL query statement below
SELECT FirstName,LastName,City,State 
FROM Person as p  left join  Address as a  ON p.PersonId=a.PersonId;
```