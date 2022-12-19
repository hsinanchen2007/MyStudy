### 解题思路

与 [第二高的薪水](https://leetcode-cn.com/problems/second-highest-salary/) 思路一致，均为 `LIMIT` 子句的运用，简单易懂。参照 [官方解释](https://leetcode-cn.com/problems/second-highest-salary/solution/di-er-gao-de-xin-shui-by-leetcode/) 对代码稍作调整即可。

#### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET n = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT (
          SELECT DISTINCT Salary
          FROM Employee
          ORDER BY Salary DESC
          LIMIT 1 OFFSET n
          )
  );
END
```


### 另一种方案

采用 `IF()` 函数可以 “符合题意” ，一句解决，可以但没必要。

这种方法思路也十分简单：

1. 查询排序后取前 N 行数据
2. 使用 `count()` 取行数 `rows` 
    - `rows < N` 则没有第 N 行数据，结果为 `NULL`
    - `rows >= N` 则取第 N 行数据

#### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT IF(result_rows<N, NULL, n_highest_salary)
      FROM (
        SELECT count(1) AS result_rows, MIN(Salary) as n_highest_salary
        FROM (
          SELECT DISTINCT Salary FROM Employee 
          ORDER BY Salary DESC 
          LIMIT N
        ) as tmp_a
      ) as tmp_b
  );
END
```

### 结语

题目不太严谨，没必要浪费时间，下一题。