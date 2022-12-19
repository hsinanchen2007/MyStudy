题目问的是每一个项目中经验最丰富的雇员是谁（经验最丰富=工龄最长）

1. 我们先筛选出每个项目最长工龄
两个表进行通过相同的employee_id进行inner join，筛选出每组的最大experience_years，输出项目和experience_years

```
select project_id, max(experience_years) ey from Project p1 inner join Employee e1 
on p1.employee_id=e1.employee_id
group by project_id
```
2. 利用子查询提取每个项目的经验最丰富的员工

用到结构 `select * from ... where (project_id,experience_years) in ...`
```
select * from Project p inner join Employee e 
on p.employee_id=e.employee_id
where (project_id,experience_years) in
(select project_id, max(experience_years) ey from Project p1 inner join Employee e1 
on p1.employee_id=e1.employee_id
group by project_id)

```

3. 在select中添加我们需要的列，查询完毕

```
select project_id,e.employee_id from Project p inner join Employee e 
on p.employee_id=e.employee_id
where (project_id,experience_years) in
(select project_id, max(experience_years) ey from Project p1 inner join Employee e1 
on p1.employee_id=e1.employee_id
group by project_id)
```