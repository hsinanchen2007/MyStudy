根据部门DepartmentId、工资Salary的先后顺序排序，然后通过变量遍历的方式得到每个人的薪水在各自部门的排名：
SELECT e.Name,e.Salary,e.DepartmentId,
@rank := IF(e.DepartmentId != @departmentId,1,IF(e.Salary < @salary AND e.DepartmentId = @departmentId, @rank + 1,@rank)) rank,
@departmentId := e.DepartmentId,@salary := e.Salary FROM employee e,
(SELECT @departmentId := NULL,@salary := NULL,@rank := 1) r ORDER BY e.DepartmentId,e.Salary DESC
![image.png](https://pic.leetcode-cn.com/06de78ea275fd305c5f7624bf370b0137a774f7ee8397bbe48785279c4982664-image.png)

然后再和部门表关联，同时筛选工资排名前三的员工：
SELECT d.Name Department,t.Name Employee,t.Salary FROM (SELECT e.Name,e.Salary,e.DepartmentId,
@rank := IF(e.DepartmentId != @departmentId,1,IF(e.Salary < @salary AND e.DepartmentId = @departmentId, @rank + 1,@rank)) rank,
@departmentId := e.DepartmentId,@salary := e.Salary FROM Employee e,
(SELECT @departmentId := NULL,@salary := NULL,@rank := 1) r ORDER BY e.DepartmentId,e.Salary DESC) t,Department d
WHERE t.DepartmentId = d.Id
AND t.rank <= 3
![image.png](https://pic.leetcode-cn.com/1aa9e673d7b43e3062a7bf7da6d22a8b2cd878a951389d6efd2cd5a08d2d6033-image.png)

