#### 方法： 使用 `<>` (`!=`) 和 `IS NULL` [Accepted]

**想法**

有的人也许会非常直观地想到如下解法。

```sql [-Sql]
SELECT name FROM customer WHERE referee_Id <> 2;
```

然而，这个查询只会返回一个结果：Zach，尽管事实上有 4 个顾客都不是 Jane 推荐的（包括 Jane 她自己）。所有没有推荐人（referee_id 字段值为 `NULL`) 的全部都小时了。为什么?

**算法**

MySQL 使用三值逻辑 —— TRUE, FALSE 和 UNKNOWN。任何与 `NULL` 值进行的比较都会与第三种值 UNKNOWN 做比较。这个“任何值”包括 `NULL` 本身！这就是为什么 MySQL 提供 `IS NULL` 和 `IS NOT NULL` 两种操作来对 `NULL` 特殊判断。

因此，在 WHERE 语句中我们需要做一个额外的条件判断 `referee_id IS NULL'。

**MySQL**

```sql [-Sql]
SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;
```
或者
```mysql [-MySql]
SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;
```

**提示**

下面的解法同样是错误的，错误原因同上。避免错误的秘诀在于使用 `IS NULL` 或者 `IS NOT NULL` 两种操作来对 NULL 值做特殊判断。

```sql [-Sql]
SELECT name FROM customer WHERE referee_id = NULL OR referee_id <> 2;
```