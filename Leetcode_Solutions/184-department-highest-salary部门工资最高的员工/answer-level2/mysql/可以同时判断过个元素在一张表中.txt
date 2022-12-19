### 解题思路
MySQL可以使用多个元素，类似Python中的元祖（a，b）是否在元组数组中一样。
```mysql
        (   SELECT
                DepartmentId, MAX(Salary)
            FROM
                Employee
            GROUP BY DepartmentId
        )
```
可以理解为元组数组。一张表只是表象。结果如图
![image.png](https://pic.leetcode-cn.com/3f1834b2bf2fe75130d2f86224d6617c793eec65280f72868b9a2af88b9ca139-image.png)
每一行都是一个(DepartmentId, MAX(Salary))的二元组。可以使用in查看是否在。


### 代码

```mysql


SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id

WHERE
        (Employee.DepartmentId , Salary) IN
        (   SELECT
                DepartmentId, MAX(Salary)
            FROM
                Employee
            GROUP BY DepartmentId
        )

```