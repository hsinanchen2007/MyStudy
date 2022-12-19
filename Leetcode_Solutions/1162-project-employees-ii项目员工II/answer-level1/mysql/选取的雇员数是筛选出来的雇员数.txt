### 解题思路
条件是什么呢？ 项目对应的雇员数。 选取的雇员数是筛选出来的雇员数

### 代码

```mysql
# Write your MySQL query statement below

-- 条件是什么呢？ 项目对应的雇员数。 选取的雇员数是筛选出来的雇员数

select project_id 
from Project
group by project_id
having count(employee_id)=(       -- 条件：雇员数
select count(employee_id) as num          -- 按项目id 计算雇员数
from Project 
group by project_id  
order by count(employee_id) desc 
limit 0,1
)


```