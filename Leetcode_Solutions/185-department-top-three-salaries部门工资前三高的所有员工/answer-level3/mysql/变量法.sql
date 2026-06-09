由于最高工资可能重复，且有的部门可能少于3个人，因此不能用`LIMIT`解决。这种组内排序问题通常需要设置变量。
- 第一步，对employee表进行排序，方便后面进行组内排序
```
SELECT *
FROM employee
ORDER BY departmentid, salary DESC
```
- 第二步，设置变量，并且进行判断。首先需要设置`@depart`变量，以判断是否在同一组内，然后要设置`@prev`变量，以判断是否存在工资相同的情况，最后设置`@rank`变量进行排序
```MySQL
SELECT t1.*,
    CASE
    WHEN @depart = t1.departmentid AND @prev = salary THEN @rank 
    WHEN @depart = t1.departmentid THEN @rank := @rank + 1
    ELSE @rank := 1
    END r,
    @depart := departmentid,
    @prev := salary
FROM
(SELECT *
FROM employee
ORDER BY departmentid, salary DESC) t1,
(SELECT @prev := 0, @rank := 0, @depart := NULL) t2
```
- 第三步，将上述查询表与depatment表连接，然后筛选出组内排序小于3的查询即可
```
SELECT d.name Department, t3.name Employee, t3.salary Salary
FROM
    (SELECT t1.*,
        CASE
        WHEN @depart = t1.departmentid AND @prev = salary THEN @rank 
        WHEN @depart = t1.departmentid THEN @rank := @rank + 1
        ELSE @rank := 1
        END r,
        @depart := departmentid,
        @prev := salary
    FROM
    (SELECT *
    FROM employee
    ORDER BY departmentid, salary DESC) t1,
    (SELECT @prev := 0, @rank := 0, @depart := NULL) t2
) t3 
JOIN department d
ON t3.departmentid = d.id
WHERE t3.r <= 3
```