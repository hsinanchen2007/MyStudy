### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

select d.dept_name, ifnull(count(s.dept_id),0) as student_number from department d
left join student s
on d.dept_id=s.dept_id 
group by d.dept_id
order by count(s.dept_id) desc, dept_name asc
```