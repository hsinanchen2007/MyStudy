1. 首先先将数据去重：SELECT DISTINCT Salary FROM Employee
2. 再将是数据按薪水降序排除：SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC
3. 分页的思想是一页一条数据，第二高的薪水则在第二页：SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1, 1
4. 考虑到极端情况：没有第二薪水则为空，使用ifnull判断：
        SELECT IFNULL( (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1, 1),null) AS SecondHighestSalary 


- 分页的其他使用：offset 
- SQL查询语句中的 limit 与 offset 的区别：
- limit y 分句表示: 读取 y 条数据
- limit x, y 分句表示: 跳过 x 条数据，读取 y 条数据
- limit y offset x 分句表示: 跳过 x 条数据，读取 y 条数据