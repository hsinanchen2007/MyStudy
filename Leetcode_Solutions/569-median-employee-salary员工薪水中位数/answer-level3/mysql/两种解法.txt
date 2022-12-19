[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
注意到每个公司的薪水升序后，中位数的下标和个数是确定的。

薪水总数N是偶数时，下标(N-1)/2和N/2位置处为中位数。N是奇数时，下标(N-1)/2为中位数。

对每个公司group by分组，统计每组个数N，确定中位数区间[beg,beg+cnt]，beg从0开始。

beg = (N-1)/2

cnt = 0或1，N为偶数时为1，N为奇数时为0。

结果命名为表A。
```
(
	SELECT E.Company,FLOOR((COUNT(*)-1)/2) AS `beg`,if(COUNT(*) % 2=1,0,1) AS `cnt`
	FROM employee AS E
	GROUP BY E.Company
) AS A
```
COUNT(*)为每组总数，FLOOR向下取整函数。

计算每个人薪水的升序排名。最小的薪水排第一，第2小的薪水排第二，…..。

薪水比较方法：
```
if (A.salary = B.salary and A.id > B.id or A.salary > B.salary)
{
    那么A的排名在B的排名后。
}
```
员工表left join员工表，得出同一个公司中，排名在每个人之前的所有人。
```
SELECT *
FROM employee AS E1
LEFT JOIN employee AS E2 
    ON(E1.company = E2.company AND (E1.salary = E2.salary AND E1.Id > E2.Id OR E1.Salary > E2.Salary))
```
那么，按E1分组后，统计每组内，E2的个数即为E1的排名，排名从0开始。

最后结果按薪水升序，命名为表B。
```
(
	SELECT E1.Id,E1.Company,E1.Salary, COUNT(E2.Salary) AS `trank`
	FROM employee AS E1
	LEFT JOIN employee AS E2 
		ON(E1.company = E2.company AND (E1.salary = E2.salary AND E1.Id > E2.Id OR E1.Salary > E2.Salary))
	GROUP BY E1.Id,E1.Company,E1.Salary
	ORDER BY E1.Company,E1.Salary
) AS B 
```
现在有了中位数区间和每个人的排名。

连接表A和表B，公司相同，B.trank在[A.beg,A.beg+A.cnt]之间的行，为中位数。
```
SELECT B.Id,B.Company,B.Salary
FROM  
(
	SELECT E.Company,FLOOR((COUNT(*)-1)/2) AS `beg`,if(COUNT(*) % 2=1,0,1) AS `cnt`
	FROM employee AS E
	GROUP BY E.Company
) AS A 
JOIN (
	SELECT E1.Id,E1.Company,E1.Salary, COUNT(E2.Salary) AS `trank`
	FROM employee AS E1
	LEFT JOIN employee AS E2 
		ON(E1.company = E2.company AND (E1.salary = E2.salary AND E1.Id > E2.Id OR E1.Salary > E2.Salary))
	GROUP BY E1.Id,E1.Company,E1.Salary
	ORDER BY E1.Company,E1.Salary
) AS B 
	ON (A.company = B.company AND B.trank BETWEEN A.beg AND (A.beg+A.cnt))
```

# 解法二
思路与解法一相同。换了一种计算公司内部人员排名的方法。

解法一采用表left join，分组再计数的方法。

这里，采用用户变量的方法，简化排名的计算。

定义用户变量：pre_company——上一行的公司字段。trank——当前行的排名，从0开始。
```
(SELECT @pre_company:= NULL,@trank:=0) AS T
```
计算排名的逻辑：
```
if (当前行的company = pre_company){
    trank = trank + 1
}else{
    trank = 0
}
```
SQL代码，结果命名为表A
```
(
	SELECT 
	id,
	company,
	salary,
	@trank:=IF(@pre_company=company,@trank+1,0) AS `trank`,
	@pre_company:=company
	FROM employee,(SELECT @pre_company:= NULL,@trank:=0) AS T
	ORDER BY company,salary
) AS A
```
计算中位数下标的方法如解法一。

薪水总数N是偶数时，下标(N-1)/2和N/2位置处为中位数。N是奇数时，下标(N-1)/2为中位数。

对每个公司group by分组，统计每组个数N，确定中位数区间[beg,beg+cnt]，beg从0开始。

beg = (N-1)/2

cnt = 0或1，N为偶数时为1，N为奇数时为0。

结果命名为表B。
```
(
	SELECT company, FLOOR((COUNT(*)-1)/2) AS `beg`, if(COUNT(*)%2=1,0,1) AS `cnt`
	FROM employee
	GROUP BY company
) AS B
```
连接表A和表B ，公司相同，B.trank在[A.beg,A.beg+A.cnt]之间的行，为中位数。
```
SELECT A.Id,A.Company,A.Salary
FROM 
(
	SELECT 
	id,
	company,
	salary,
	@trank:=IF(@pre_company=company,@trank+1,0) AS `trank`,
	@pre_company:=company
	FROM employee,(SELECT @pre_company:= NULL,@trank:=0) AS T
	ORDER BY company,salary
) AS A
JOIN 
(
	SELECT company, FLOOR((COUNT(*)-1)/2) AS `beg`, if(COUNT(*)%2=1,0,1) AS `cnt`
	FROM employee
	GROUP BY company
) AS B
ON (A.company=B.company AND A.trank BETWEEN B.beg AND B.beg+B.cnt)
```