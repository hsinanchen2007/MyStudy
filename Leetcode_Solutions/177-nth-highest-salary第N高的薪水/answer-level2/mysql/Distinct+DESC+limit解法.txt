### 解题思路
此处撰写解题思路
	判断 N<0 ? avg(Salary):index=N的data
### 代码

```mysql

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
	# Write your MySQL query statment
	if N<0 then
            Return (Select avg(Salary) from Employee);
            -- 若要查找的N小于0,则返回工资Salary的平均值
			-- 少了对查找N层的最大限制(越界问题未处理)
	else
		set N = N-1;
		Return(
			Select IFNULL(
				(
					Select Distinct Salary
					From Employee
					Order by Salary DESC
					limit N,1
				),null
			) as NthHighestSalary
	    );
	end if;
END
```