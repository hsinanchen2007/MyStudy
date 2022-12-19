#### 方法：使用 `LIMIT` [Accepted]

**算法**

首先，我们使用 `GROUP BY` 选择 **customer_number** 和相应的订单数目。
```sql [-Sql]
SELECT
    customer_number, COUNT(*)
FROM
    orders
GROUP BY customer_number
```

| customer_number | COUNT(*) |
|-----------------|----------|
| 1               | 1        |
| 2               | 1        |
| 3               | 2        |

将它们按照订单数目降序排序之后，第一条记录的 **customer_number** 就是答案。

| customer_number | COUNT(*) |
|-----------------|----------|
| 3               | 2        |

在 MySQL 中， [LIMIT](https://dev.mysql.com/doc/refman/5.7/en/select.html) 语句可以被用来限制 SELECT 语句的返回行数。它需要传入 1 个或 2 个非负整数参数，第一个参数 offset 表示跳过前面多少行后开始取数据，第二个参数表示最多返回多少行的数据。默认 offset 为 0（不是 1）。

`LIMIT` 语句也可以只使用一个参数，这个参数的含义是从结果的第一行开始返回的行数。所以 `LIMIT 1` 会返回第一行的记录。

**MySQL**

```sql [-Sql]
SELECT
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1
;
```