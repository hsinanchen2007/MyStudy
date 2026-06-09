击败50%的选手...想法比较简单
第一步，计算中位数的需要，先算出每个公司有多少个员工，记为num
第二步，将每个公司员工工资从小到大排序
第三步，中位数计算公式，如果有奇数个员工，中位数median = (num + 1)/2，如果有偶数个员工，中位数有两个，分别是num/2和num/2 + 1
```MySQL
SELECT t4.Id, t4.Company, t4.Salary
FROM
(SELECT t1.*,
    (num + 1)/2 median,
    CASE
    WHEN @isr = t1.company THEN @rank := @rank + 1
    ELSE @rank := 1
    END r,
    @isr := t1.company
FROM
    (SELECT *
    FROM employee
    ORDER BY company, salary) t1
    JOIN
    (SELECT company, COUNT(*) num
    FROM employee
    GROUP BY company) t2
    ON t1.company = t2.company,
    (SELECT @isr := NULL, @rank := NULL) t3
)t4
WHERE r BETWEEN median - 0.5 AND median + 0.5
ORDER BY t4.company, t4.salary
```
