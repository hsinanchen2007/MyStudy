### 解题思路
此处撰写解题思路
1.使用dense_rank 函数，先求出排名
select name,salary,departmentid,dense_rank()  over(partition by departmentid
order by salary desc) as ranking from employee 
2.join部门表，查出相关结果

### 代码

```mssql
/* Write your T-SQL query statement below */
select 
    d.Name as Department,
    e.Name as Employee,
    e.salary as Salary
 from (
select name,salary,departmentid,dense_rank()  over(partition by departmentid
order by salary desc) as ranking from employee ) as e 
join Department as d on d.id=e.departmentid 
where e.ranking<=3
```