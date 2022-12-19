### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below 
SELECT ifNull((select MAX( distinct Salary) FROM Employee  where Salary< (SELECT MAX( distinct Salary) FROM Employee)) ,null ) as   SecondHighestSalary 

``` 
### 当然还是看自己那块不熟悉,看那块知识点不好