#### 方法：使用 `OUTER JOIN` 和 `NOT IN` [Accepted]

**想法**

如果我们知道向 `RED` 公司销售东西的人，那么我们要知道没有向 `RED` 公司销售东西的人会非常容易。

**算法**

首先，我们用一个临时表保存向 `RED` 公司销售过东西的人，然后利用姓名信息将这个表和 **salesperson** 表建立联系。

```sql []
SELECT
    *
FROM
    orders o
        LEFT JOIN
    company c ON o.com_id = c.com_id
WHERE
    c.name = 'RED'
;
```
>注意： "LEFT OUTER JOIN" 也可以写作 "LEFT JOIN" 。

```
| order_id | date     | com_id | sales_id | amount | com_id | name | city   |
|----------|----------|--------|----------|--------|--------|------|--------|
| 3        | 3/1/2014 | 1      | 1        | 50000  | 1      | RED  | Boston |
| 4        | 4/1/2014 | 1      | 4        | 25000  | 1      | RED  | Boston |
```

显然，列 *sales_id* 在 **salesperson** 中，所以我们把它当做子查询并使用 [`NOT IN`](https://dev.mysql.com/doc/refman/5.7/en/any-in-some-subqueries.html) 获得想要的数据。

```sql []
SELECT
    s.name
FROM
    salesperson s
WHERE
    s.sales_id NOT IN (SELECT
            o.sales_id
        FROM
            orders o
                LEFT JOIN
            company c ON o.com_id = c.com_id
        WHERE
            c.name = 'RED')
;
```
