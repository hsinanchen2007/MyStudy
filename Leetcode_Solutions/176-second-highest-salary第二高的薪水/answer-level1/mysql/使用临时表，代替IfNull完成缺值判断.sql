### 解题思路
此处撰写解题思路
	Select(一个临时的查询表)，若查询不到则为null
		(实际上是Select(Select xxx)),若第二个为null则return null(空)，然后变成Select(null)

	临时表的Select()输出结果{"headers": ["Salary"], "values": [[null]]}
	然后 Select(null) -> Output: null
### 代码

```mysql
# Write your MySQL query statement below


Select(
	Select Distinct
		Salary
	From
		Employee
	Order by Salary DESC
	Limit 1 Offset 1
) as SecondHighestSalary

```