>补充一个提交注意点，部门薪水前三高包含了相同薪水下排名相同的意思
## 问题
查询出每个部门 **薪水前三高** 的员工  
我们可以分解查询步骤,再组合
## 简化问题（分步骤）
分解步骤的思路,可以依据必要存在的步骤进行分解  
1.根据 **部门 (升)**，**薪水 (降)** 顺序查询出每个部门的员工 **(Department, Employee, Salary)**
```sql
SELECT dep.Name Department, emp.Name Employee, emp.Salary
FROM Employee emp
INNER JOIN Department dep ON emp.DepartmentId = dep.Id
ORDER BY emp.DepartmentId, emp.Salary DESC
```
2.每个部门的员工根据薪水进行排序
>由于原本没有排序的字段,所以这里就需要自定义变量补充一个字段出来

```sql
## 先(部门,薪水)去重,再 部门(升),薪水(降) 排序
SELECT te.DepartmentId, te.Salary,
       CASE 
            WHEN @pre = DepartmentId THEN @rank:= @rank + 1
            WHEN @pre := DepartmentId THEN @rank:= 1
       END AS RANK
FROM (SELECT @pre:=null, @rank:=0)tt,
     (## (部门,薪水)去重,根据 部门(升),薪水(降) 排序
         SELECT DepartmentId,Salary
         FROM Employee
         GROUP BY DepartmentId,Salary
         ORDER BY DepartmentId,Salary DESC
     )te
```
## 组合步骤
组合步骤时,尽量将每个步骤变成一个 **结果集（不存在二次查询）**  
再将所有步骤的 **结果集进行关联**，从而提高性能
```sql
SELECT dep.Name Department, emp.Name Employee, emp.Salary
FROM (## 自定义变量RANK, 查找出 每个部门工资前三的排名
        SELECT te.DepartmentId, te.Salary,
               CASE 
                    WHEN @pre = DepartmentId THEN @rank:= @rank + 1
                    WHEN @pre := DepartmentId THEN @rank:= 1
               END AS RANK
        FROM (SELECT @pre:=null, @rank:=0)tt,
             (## (部门,薪水)去重,根据 部门(升),薪水(降) 排序
                 SELECT DepartmentId,Salary
                 FROM Employee
                 GROUP BY DepartmentId,Salary
                 ORDER BY DepartmentId,Salary DESC
             )te
       )t
INNER JOIN Department dep ON t.DepartmentId = dep.Id
INNER JOIN Employee emp ON t.DepartmentId = emp.DepartmentId and t.Salary = emp.Salary and t.RANK <= 3
ORDER BY t.DepartmentId, t.Salary DESC ## t 结果集已有序,根据该集合排序
```


