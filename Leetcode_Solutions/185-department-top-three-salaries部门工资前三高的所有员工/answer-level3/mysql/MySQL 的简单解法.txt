### 解题思路

此题目是 [分数排名](https://leetcode-cn.com/problems/rank-scores/) 与 [部门工资最高的员工](https://leetcode-cn.com/problems/department-highest-salary/) 两者的解法结合运用。
简单的思路如下
1. 统计工资排名
2. 选取工资前 3 
3. 关联 `Department` 与 `Employee` 获得最终结果

### 代码

比较容易理解的写法是照搬前述【分数排名】，将工资排名作为临时表，后关联 `Department` 与 `Employee` 得到结果

```mysql
# Write your MySQL query statement below

SELECT d.Name `Department`, e1.Name `Employee`, e1.Salary `Salary`
FROM Department d,
     Employee e1,
     (SELECT e2.Id,
             (SELECT COUNT(DISTINCT e3.Salary)
              FROM Employee e3
              WHERE e2.Salary <= e3.Salary
                AND e2.DepartmentId = e3.DepartmentId
             ) AS salary_rank
      FROM Employee e2
      ORDER BY e2.DepartmentId, salary_rank
     ) AS tmp
WHERE tmp.Id = e1.Id
  AND tmp.salary_rank <= 3
  AND e1.DepartmentId = d.Id
ORDER BY d.Id, e1.Salary DESC;
```

上述写法有明显的多余嵌套，临时表存在的意义仅为了查询工资前 3 ，稍作优化

```mysql
# Write your MySQL query statement below

SELECT d.Name `Department`, e1.Name `Employee`, e1.Salary `Salary`
FROM Department d,
     Employee e1
WHERE e1.DepartmentId = d.Id
  AND 3 >= (
    SELECT COUNT(DISTINCT e2.Salary)
    FROM Employee e2
    WHERE e1.Salary <= e2.Salary
      AND e1.DepartmentId = e2.DepartmentId)
ORDER BY d.Id, e1.Salary DESC;
```

