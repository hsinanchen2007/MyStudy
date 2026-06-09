### 解题思路

我看到这类分组排序题目，第一反应就是使用变量
变量初始化 `(SELECT @rank:=0, @tmpid:='',@val:='') b`
注意 `@rank:=@rank+(@val>a.Salary)` 和 `@rank:=@rank+1` 的区别，代码在此，尽可尝试

### 代码

```mysql

# 并列排名
SELECT d.name Department,t.Employee,t.Salary FROM (
    SELECT DepartmentId,Name Employee,Salary,
    IF(@tmpid=a.DepartmentId, @rank:=@rank+(@val>a.Salary), @rank:=1) rank,
    @rank num, @tmpid:=a.DepartmentId, @val:=a.Salary
    FROM (SELECT * FROM Employee ORDER BY DepartmentId,Salary DESC,id) a,
        (SELECT @rank:=0, @tmpid:='',@val:='') b
) t JOIN Department d ON t.DepartmentId = d.id WHERE num <= 3

```
![6.png](https://pic.leetcode-cn.com/787158dc3ec96f1ed5ba7e5bf4c8b68185830d981e82cfa170c5240297483e24-6.png)

```mysql

# 拓展 —— 并列排名2
SELECT d.name Department,t.name Employee,t.Salary,rank FROM (
    SELECT a.*,
    @rank:=IF(@tmpid=a.DepartmentId,IF(@val=Salary,@rank,@num),@num:=1) AS rank,
    @tmpid:=a.DepartmentId,
    @val:=Salary,
    @num:=@num+1
    FROM (SELECT * FROM Employee ORDER BY DepartmentId,Salary DESC,id) a,
        (SELECT @tmpid:=null,@val:=NULL,@num:=1,@rank:=0) b
    ORDER BY DepartmentId,Salary DESC,id
) t JOIN Department d ON t.DepartmentId = d.id

```
![4.png](https://pic.leetcode-cn.com/987c6214135093ac913c7de888d6effa16c4399c3c9796a4b89e757dbf90a466-4.png)


