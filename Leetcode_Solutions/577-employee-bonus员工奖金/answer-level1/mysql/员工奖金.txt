#### 方法： 使用 `OUTER JOIN` 和 `WHERE` 语句 [Accepted]

**想法**

将表 **Employee** 和 **Bonus** 连接，然后使用 `WHERE` 语句获得想要的记录。

**算法**

由于外键 **Bonus.empId** 引用了 **Employee.empId** 且有一些雇员没有 bonus 记录，所以第一步中，我们使用 `OUTER JOIN` 将两个表连接。

```sql [-Sql]
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT OUTER JOIN
    Bonus ON Employee.empid = Bonus.empid
;
```
>注意： "LEFT OUTER JOIN" 可以被写作 "LEFT JOIN" 。

运行这段代码，样例输入得到的输出如下所示。

```
| name   | bonus |
|--------|-------|
| Dan    | 500   |
| Thomas | 2000  |
| Brad   |       |
| John   |       |
```
`Brad` 和 `John` 的 `bonus` 值为空，在数据库中会被记为 `NULL`。从概念上来说，`NULL` 意味着 “一个缺失的未知的值” 。可以查看 MySQL 手册 [如何处理 NULL 值](https://dev.mysql.com/doc/refman/5.7/en/working-with-null.html) 了解更多信息。除此以外，我们使用 `IS NULL` 和 `IS NOT NULL` 来将一个值与 `NULL` 做比较。

最后，我们增加一个 `WHERE` 语句以筛选出我们想要的记录。

**MySQL**

```sql [-Sql]
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee
        LEFT JOIN
    Bonus ON Employee.empid = Bonus.empid
WHERE
    bonus < 1000 OR bonus IS NULL
;
```
