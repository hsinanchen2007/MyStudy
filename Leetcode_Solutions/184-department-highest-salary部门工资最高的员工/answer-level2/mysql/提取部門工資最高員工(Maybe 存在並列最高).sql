### 解题思路
分步撰寫：
step1.建立子查詢T：應用group by求出每個部門（ID，name）的最高薪資
step2.建立子查詢T與表Employee的聯結：提取出每個部門最高薪資對應的員工姓名（存在並列最高的情況也能一併提出）
PS：
1.group by 返回唯一值，無法處理並列最高薪資的情況，因此需要與聯結並用
2.子查詢與表Employee的聯結鍵有兩個：公司Id及薪資
### 代码

```mysql
# Write your MySQL query statement below
select T.Name as Department,
       Employee.Name as Employee,
       T.Salary as Salary
from
(select D.Id,D.Name,max(E.Salary) as Salary
from Employee as E join Department as D on E.DepartmentId=D.Id
group by D.Name
) as T join Employee on Employee.DepartmentId=T.Id and T.Salary=Employee.Salary;
```