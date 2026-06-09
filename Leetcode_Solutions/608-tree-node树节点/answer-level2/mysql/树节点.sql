#### 方法 1：使用 `UNION` [Accepted]

**想法**

我们可以按照下面的定义，求出每一条记录的节点类型。
* Root: 没有父节点
* Inner: 它是某些节点的父节点，且有非空的父节点
* Leaf: 除了上述两种情况以外的节点

**算法**

将上述定义转化，我们可以得到下面的代码。

根节点是没有父节点的节点。

```sql []
SELECT
    id, 'Root' AS Type
FROM
    tree
WHERE
    p_id IS NULL
```

叶子节点是没有孩子节点的节点，且它有父亲节点。

```sql []
SELECT
    id, 'Leaf' AS Type
FROM
    tree
WHERE
    id NOT IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
```

内部节点是有孩子节点和父节点的节点。

```sql []
SELECT
    id, 'Inner' AS Type
FROM
    tree
WHERE
    id IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
```

所以本题的一种解法是将这些情况用 `UNION` 合并起来。

```sql []
SELECT
    id, 'Root' AS Type
FROM
    tree
WHERE
    p_id IS NULL

UNION

SELECT
    id, 'Leaf' AS Type
FROM
    tree
WHERE
    id NOT IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL

UNION

SELECT
    id, 'Inner' AS Type
FROM
    tree
WHERE
    id IN (SELECT DISTINCT
            p_id
        FROM
            tree
        WHERE
            p_id IS NOT NULL)
        AND p_id IS NOT NULL
ORDER BY id;
```

#### 方法 II：使用流控制语句 `CASE` [Accepted]

**算法**

与上面解法类似，本解法使用流控制语句，流控制语句对基于不同输入产生不同输出非常有效。本方法中，我们使用 [`CASE`](https://dev.mysql.com/doc/refman/5.7/en/case.html) 语句。

```sql [-sql]
SELECT
    id AS `Id`,
    CASE
        WHEN tree.id = (SELECT atree.id FROM tree atree WHERE atree.p_id IS NULL)
          THEN 'Root'
        WHEN tree.id IN (SELECT atree.p_id FROM tree atree)
          THEN 'Inner'
        ELSE 'Leaf'
    END AS Type
FROM
    tree
ORDER BY `Id`
;
```
>MySQL 除了 `CASE` 语句以外还提供了不同的流控制语句。你可以尝试将上面的方法用 [`IF`](https://dev.mysql.com/doc/refman/5.7/en/control-flow-functions.html#function_if) 重写。

#### 方法 III；使用 `IF` 函数 [Accepted]

**算法**

我们还可以使用 [`IF`](https://dev.mysql.com/doc/refman/5.7/en/control-flow-functions.html#function_if) 函数来避免复杂的流控制语句。

```sql []
SELECT
    atree.id,
    IF(ISNULL(atree.p_id),
        'Root',
        IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM
    tree atree
ORDER BY atree.id
```

>注意：此解法由 [@richarddia](https://discuss.leetcode.com/user/richarddia) 提出。
