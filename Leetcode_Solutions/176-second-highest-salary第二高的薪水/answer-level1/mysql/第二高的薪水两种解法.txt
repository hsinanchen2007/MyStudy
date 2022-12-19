### 题解一：使用 limit
回忆一下 limit 的用法

```mysql
limit N     # 返回 N 条记录
offset M    # 跳过 M 条记录，M 默认为 0
limit M,N   # 相当于 limit N offset M，从第 M 条记录开始，返回 N 条记录
```

将 Salary **去重**后**降序排列**，再**返回第二条记录**可得第二大的值
也许只有一个 Salary 值，将返回 null
```mysql
select (
	select DISTINCT Salary
	from Employee
	order by Salary DESC
	limit 1,1) 
as SecondHighestSalary;
```

### 题解二：使用 max 函数
回忆一下 max 的用法
```mysql
max(字段名)  # 返回该字段的最大值
```
找出**小于该字段最大值**的**最大值**，即为第二大值
```mysql
select max(Salary) as SecondHighestSalary 
from Employee
where Salary < (
    select max(Salary) from Employee
);
```

