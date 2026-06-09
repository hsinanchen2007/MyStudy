### 解题思路
**分步骤详细说明，首先我们想得到薪资按部门的排序(降序)，其次我们要把部门ID（departmentid）替换成
部门（department），最后我们要按部门取出前三。**

1.
```
SELECT department.name as department,employee.name as employee,salary 
        FROM employee INNER JOIN department
        WHERE employee.departmentId=department.Id order by department,Salary desc
```
代码解释：**从employee和department两张表中，按部门号相同的，进行拼接。拼接后选出department,employee(employee表中的name),salary并按部分和薪水排序。第一步是选择表还没做筛选。**
2.选出每个部门的前三。

    这一步是核心，也是这道题最难理解的。
    我们的思路是找两个表格进行相互比较，比如第一个表中第一大的是max（90000），那我再找一个表用做和max比较
    如果没有比max大的就取出max。比较完第一，我们比较第二joe（85000），找一个和joe比较，没有比joe大的取出joe。以此类推。
    **那我们这个比较的对象我们当然只能选相同的表（对象都包含参能比较）。
    那么我们选中两个相同的表**
e1: 
        +----+-------+--------+--------------+  
        | Id | Name  | Salary | DepartmentId |
        +----+-------+--------+--------------+
        | 1  | Joe   | 85000  | 1            |
        | 2  | Henry | 80000  | 2            |
        | 3  | Sam   | 60000  | 2            |
        | 4  | Max   | 90000  | 1            |
        | 5  | Janet | 69000  | 1            |
        | 6  | Randy | 85000  | 1            |
        | 7  | Will  | 70000  | 1            |
        +----+-------+--------+--------------+

e2:
        +----+-------+--------+--------------+
        | Id | Name  | Salary | DepartmentId |
        +----+-------+--------+--------------+
        | 1  | Joe   | 85000  | 1            |
        | 2  | Henry | 80000  | 2            |
        | 3  | Sam   | 60000  | 2            |
        | 4  | Max   | 90000  | 1            |
        | 5  | Janet | 69000  | 1            |
        | 6  | Randy | 85000  | 1            |
        | 7  | Will  | 70000  | 1            |
        +----+-------+--------+--------------+

    我们的比较条件如何选择？就试着从运算符里选。>,<,=。我们选<试试。
    我们让e1<e2,where e1<e2是我们的筛选条件，我们一个一个比较。我们先将工资表排序，
        +------------+----------+--------+
        | Department | Employee | Salary |
        +------------+----------+--------+
        | IT         | Max      | 90000  |
        | IT         | Randy    | 85000  |
        | IT         | Joe      | 85000  |
        | IT         | Will     | 70000  |
        | Sales      | Henry    | 80000  |
        | Sales      | Sam      | 60000 

    值比较同部门salary

            当 e1=90000，where e1<e2，筛选出 e2=[null]
            当 e1=85000, where e1<e2，筛选出 e2=[90000]
            当 e1=85000, where e1<e2，筛选出 e2=[90000]
            当 e1=70000, where e1<e2，筛选出 e2=[90000,85000,85000]
            当 e1=69000, where e1<e2，筛选出 e2=[90000,85000,85000,70000]

      我们想选出e1中前三，就是e1=9000，85000，85000，70000 →→→→→→  e2选前四行。
    怎么把前四行选出来，我们可以给e2做个计数，if count(e2)<4,就能得到想要的,那我们再进一步,
    给e2做个去重count(distinct e2)，那么我们的条件优化为 if count(e2)<3。
      总结：当数据库去一行一行筛选，每读入一个e1值就做一次判断，如果条件成立，选出e1。（说了句废话）
      代码：前面说过我们选<试试，因为我们先选出e1，再和选出的e2做比较，顺序反了上面推出的条件就不成立了。
      sql执行顺序是先from选出表，再where判断，当为真挑出值。

```
select e1.salary from e1    
where 
(
    select count(distinct e2.salary)
    from  e2
    where e1.salary<e2.salary AND e1.department = e2.Department
)  <3
;
```


### 代码

```mysql
# Write your MySQL query statement below
    

select e1.department as Department,e1.employee as Employee,e1.salary as Salary from (SELECT department.name as department,employee.name as employee,salary 
        FROM employee INNER JOIN department
        WHERE employee.departmentId=department.Id order by department,Salary desc) as e1
where 3>
(
    select count(distinct e2.salary)
    from (SELECT department.name as department,employee.name as employee,salary 
        FROM employee INNER JOIN department
        WHERE employee.departmentId=department.Id order by department,Salary desc) as e2
    where e2.salary > e1.salary AND e1.department = e2.Department
)
;


```