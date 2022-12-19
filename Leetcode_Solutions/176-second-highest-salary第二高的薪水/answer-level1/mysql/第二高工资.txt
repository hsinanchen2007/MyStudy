### 解题思路
认识了mysql的控制流函数ifnull（a,b）,如果a=null，则返回b ，对于复合的select语句记得加一个（），不然会出错
还有nullif（a，b）如果a==b，则return null，else return a
还有if（e1,e2,e3)
![数据库.png](https://pic.leetcode-cn.com/55f5db84cfab73093d529c9226790d59bcef3355a0dec5330ab38d8d9de1319c-%E6%95%B0%E6%8D%AE%E5%BA%93.png)
还有case的用法，见官方文档
![image.png](https://pic.leetcode-cn.com/a858dfad8efa656d144f137eb888c2cf6330dd7b1e5ca76c100361e5dd7631d7-image.png)




### 代码

```mysql
# Write your MySQL query statement below
select
ifnull((select Employee.Salary
from Employee
Group by Salary desc
limit 1 offset 1),null) as SecondHighestSalary ;
```