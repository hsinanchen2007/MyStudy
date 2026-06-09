                                 * 窗口函数-排序函数区别 * 
- rank():跳跃式排序——比如分数为99，99，90，89，那么通过这个函数得到的排名为1，1，3，4
- dense_rank():并列连续型排序——比如分数为90，99，99，89，那么通过这个函数得到的排名为1，1，2，3
- row_number():连续型排序——比如分数为99，99，90，89，那么通过这个函数得到的排名为1，2，3，

所以这道题使用排序函数dense_rank()比较合适，使用窗口函数比较简洁且易理解
```

SELECT
    Department,Employee,Salary
FROM
    (SELECT
        Department.Name AS Department,
        Employee.Name AS Employee,
        Employee.Salary AS Salary,
        DENSE_RANK() over(PARTITION BY Department.Id ORDER BY Employee.Salary DESC) as rank
        FROM
            Employee JOIN Department 
        ON
            Employee.DepartmentId=Department.Id
    )rk
WHERE rk.rank<4
```


注：查资料说mysql只有在8.0以上的版本才支持窗口函数。