### 解题思路
此处撰写解题思路
	
	·思路：
		因为需要‘对比’，所以Employee表一式两份，表a和表b。
		通过Join链接a，b。
		通过On给出筛选条件。

### 代码

```mysql
# Write your MySQL query statement below
Select
	a.NAME as Employee
From
	Employee as a 
Join 
	Employee as b
On
	a.ManagerId = b.Id
		And a.Salary > b.Salary
```