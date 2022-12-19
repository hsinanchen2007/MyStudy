#### 表的自连接解法
```sql
SELECT IFNULL(MAX(a.Salary),NULL) AS SecondHighestSalary
FROM Employee a JOIN Employee b 
    ON a.Salary < b.Salary 
```
- a.Salary的值永远小于b.Salary，所以可以查找a.Salary的最大值得出第二高的Salary。
- mysql中用IFNULL判断NULL，SQL server中用ISNULL判断NULL，oracle用NVL。
- 函数参考 [菜鸟](https://www.runoob.com/sql/sql-isnull.html)