### 解题思路
不用LIMIT,OFFSET，只用RANK解决

### 代码

```mysql
# Write your MySQL query statement below
SELECT
  IFNULL(e.salary, NULL) AS SecondHighestSalary
FROM
  (
    SELECT
      1 AS rank
    UNION
    SELECT
      2 AS rank
    UNION
    SELECT
      3 AS rank
  ) r
  LEFT JOIN (
    SELECT
      e.salary,
      @row_number := @row_number + 1 AS rank
    FROM
      (
        SELECT
          DISTINCT salary
        FROM
          employee
      ) e,
      (
        SELECT
          @row_number := 0
      ) AS t
    ORDER BY
      e.salary DESC
  ) e ON r.rank = e.rank
WHERE
  r.rank = 2
```