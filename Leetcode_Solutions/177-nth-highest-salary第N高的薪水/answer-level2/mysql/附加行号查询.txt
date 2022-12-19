### 解题思路
思路：给查询结果添加行号，并进行去重查询，按工资大到小排序，所以第N高工资，也就是rownum为N的记录。
我的思路是比较复杂点，其实写SQL不应该把问题复杂化，在这里写这个思路也是告诫自己也警醒别人，不要学我走弯路（大概率也没人会）

### 代码
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        select
            t.salary
        from
        (
            SELECT 
                @rownum := @rownum + 1 as rownum,
                e.salary
            FROM
            (SELECT 
                @rownum := 0) r,
            (select distinct salary from employee ) e 
            where 1 =1
            order by e.salary desc
        ) t
        where t.rownum = N 
  );
END