#### 方法：使用 `OUTER JOIN` 和 `COUNT(expression)` [Accepted]

**想法**

使用 `GROUP BY` 函数将一个部门中的学生进行聚合，然后使用 `COUNT` 函数来统计每个部门数据的数目。

**算法**

我们可以使用 `OUTER JOIN` 来对所有部门进行查询。问题的难点在于目前没有学生的部门数据应该展示为 `0`。有的人会用 `COUNT(*)` 写出如下查询。

```sql [-Sql]
SELECT
    dept_name, COUNT(*) AS student_number
FROM
    department
        LEFT OUTER JOIN
    student ON department.dept_id = student.dept_id
GROUP BY department.dept_name
ORDER BY student_number DESC , department.dept_name
;
```

不幸的是，这个写法对于像 'Law' 这样现在还没有学生的部门返回 '1' 。
```
| dept_name   | student_number |
|-------------|----------------|
| Engineering | 2              |
| Law         | 1              |
| Science     | 1              |
```
实际上，我们可以使用 `COUNT(expression)` 语句，因为如果 `expression is null`，那么这条记录不会被计数。你可以参考 [MySQL 手册](https://dev.mysql.com/doc/refman/5.7/en/counting-rows.html) 来了解更多细节。

因此，修改了上面的问题后，一个正确的解法如下。

**MySQL**

```sql [-Sql]
SELECT
    dept_name, COUNT(student_id) AS student_number
FROM
    department
        LEFT OUTER JOIN
    student ON department.dept_id = student.dept_id
GROUP BY department.dept_name
ORDER BY student_number DESC , department.dept_name
;
```
