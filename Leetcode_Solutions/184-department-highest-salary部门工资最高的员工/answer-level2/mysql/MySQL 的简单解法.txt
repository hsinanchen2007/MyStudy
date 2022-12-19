### 解题思路

`Employee` 表中包含 `Department` 的关联信息，简单的思路如下
1. 查询 `Employee` 表，使用聚合函数 [`MAX()`](https://dev.mysql.com/doc/refman/5.7/en/group-by-functions.html#function_max) 可获取部门的最高工资。此查询已经得到题目要求【部门工资最高的员工】
    ```mysql
    +--------------+------------+
    | DepartmentId | max_salary |
    +--------------+------------+
    |            1 |      90000 |
    |            2 |      80000 |
    +--------------+------------+
    ```
2. 根据上述信息，关联 `Employee` 与 `Department` 表，查询到 `Department.Name` 等字段即可。

### 代码

按照上述思路，比较直观的代码如下

```mysql
# Write your MySQL query statement below
SELECT d.Name `Department`, e.Name `Employee`, e.Salary `Salary`
FROM Department d,
     Employee e,
     (SELECT e.DepartmentId, MAX(e.Salary) AS max_salary
      FROM Employee e
      GROUP BY e.DepartmentId) AS tmp
WHERE d.Id = e.DepartmentId
  AND d.Id = tmp.DepartmentId
  AND e.Salary = tmp.max_salary;
```

由于 *MySQL* 中 [`IN()`](https://dev.mysql.com/doc/refman/5.7/en/comparison-operators.html#operator_in) 操作符可以进行 *row constructors* 比较运算（没有找到比较合适的翻译，可以理解为逐行逐列比较），也可以采用以下写法

```mysql
SELECT d.Name `Department`, e.Name `Employee`, e.Salary `Salary`
FROM Department d,
     Employee e
WHERE d.Id = e.DepartmentId
  AND (e.DepartmentId, e.Salary)
    IN (SELECT e.DepartmentId, MAX(e.Salary)
        FROM Employee e
        GROUP BY e.DepartmentId);
```