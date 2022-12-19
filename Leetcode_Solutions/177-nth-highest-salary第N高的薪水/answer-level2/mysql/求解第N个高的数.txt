### 解题思路
此处撰写解题思路

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set n=N-1;
  RETURN(
      # Write your MySQL query statement below.
      select ifnull(
        (
            SELECT DISTINCT Salary getNthHighestSalary
                from Employee
                order by Salary DESC
                LIMIT n,1
        ),NULL)
  );
END
```
题目意思可以理解为创建一个函数
使用begin 和return命令 
求解第几个的时候用的是limit 限制第几个 limit N,M 是指从第M个记录开始说N个数
在开始的时候使用set先执行n = N-1;
ifnull（字段1，字段2）指的是如果字段1为null的时候，用字段2来表示，理解本题的话就是，如果用选中的第N高的数是NULL的话，就用null表示。注意格式和括号的使用。
end。