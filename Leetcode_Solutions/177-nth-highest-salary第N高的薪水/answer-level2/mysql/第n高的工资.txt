### 解题思路
limit a,b这个方法好，跳过a行，取b行
只需要把salary的这列降序排列，N取哪个， n=N-1，但是目前表里没有重复的工资的，如果有重复工资，不让按去重计算n高
的工资，要怎么算？

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set n=N-1;
  RETURN (
    select distinct salary from employee  order by salary desc limit n,1
  );
  end
```
