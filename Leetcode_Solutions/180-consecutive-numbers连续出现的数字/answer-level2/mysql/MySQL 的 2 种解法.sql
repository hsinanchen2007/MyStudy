### 解题思路

按照题意，在保证 `Id` 连续的前提下， 最简单的解法是采用 `JOIN` 计算 `Id` 差值

#### 代码

```mysql
SELECT DISTINCT a.Num AS ConsecutiveNums
FROM `Logs` a,
     `Logs` b,
     `Logs` c
WHERE a.Id = b.Id - 1
  AND b.Id = c.Id - 1
  AND a.Num = b.Num
  AND b.Num = c.Num;
```

很明显，这种解法是有严格限制的，仅为了解此题而存在：

1. `Id` 必须连续。这在实际生产环境中几乎不可能
2. `JOIN` 表数量不多的情况下性能尚可，但如果是查找连续 N 次出现的数字，`JOIN` N 个表有性能问题

### 另一种思路

参考 [评论](https://leetcode-cn.com/problems/consecutive-numbers/comments/6040) 。在 *MySQL* 中，提供了 [*user-defined variable*](https://dev.mysql.com/doc/refman/5.7/en/user-variables.html) ，可用于暂存、计算，与控制流 [`CASE`](https://dev.mysql.com/doc/refman/5.7/en/control-flow-functions.html#operator_case) 或 [`IF`](https://dev.mysql.com/doc/refman/5.7/en/control-flow-functions.html#function_if) 完成逻辑处理。
- 用户变量
    - 赋值 `@var := 1`
    - 比较表达式 `@var = 1` , `@var > 1`
    - 用户变量在 *client* 退出 *session* 时才会自动释放，所以在每次计数完后，都需要重新初始化定义的变量
        ```mysql
        # 采用类似的形式初始化
        SELECT @var := NULL 
        ```
- 控制流
    - `CASE` 操作符 `CASE WHEN [condition] THEN result [WHEN [condition] THEN result ...] [ELSE result] END`
    - `IF` 操作符 `IF(expr1,expr2,expr3)`

#### 代码

采用 `CASE` 实现，较 `IF` 可读性更好。

```mysql
# Write your MySQL query statement below
SELECT DISTINCT Num AS ConsecutiveNums
FROM (SELECT Num,
             CASE
                 WHEN @prev = Num
                     THEN @count := @count + 1
                 WHEN (@prev := Num) IS NOT NULL
                     THEN @count := 1
                 END AS counts
      FROM `Logs`,
           (SELECT @prev := NULL, @count := NULL) AS init
     ) AS tmp
WHERE tmp.counts >= 3;
```

