### 解题思路
1、添加两个字段，生产一个新表，一个字段用来判断是否一样，一个记录排名。
select id,departmentid,salary,@last_salary:= '', @rank:=1 , @last_department:= ''  
from employee 
group by departmentid
order by salary desc;

2、开始对数据进行排名--------有问题----已解决（分组排序可将分组条件放入ORDER BY 中）

select id,departmentid,salary,
	   @rank:= 
	   case when @last_salary = salary and @last_department = departmentid then @rank
			when @last_salary != salary and @last_department = departmentid then @rank+1 
			when @last_department != departmentid then 1
	   end as row_rank,
	   @last_salary := salary,
	   @last_department := departmentid
from (select id,departmentid,salary,@last_salary:= '', @rank:=0 , @last_department:= ''  
from employee 
order by departmentid,salary desc )a;


##将满足条件的员工ID取出
select id from (select id,departmentid,salary,
	   @rank:= 
	   case when @last_salary = salary and @last_department = departmentid then @rank
			when @last_salary != salary and @last_department = departmentid then @rank+1 
			when @last_department != departmentid then 1
	   end as row_rank,
	   @last_salary := salary,
	   @last_department := departmentid
from (select id,departmentid,salary,@last_salary:= '', @rank:=0 , @last_department:= ''  
from employee 
order by departmentid,salary desc )a)b
where row_rank <=3;

###最终查询语句
3、select d.name department,c.name employee,salary
from employee c join department d  on c.departmentid = d.Id 
where c.Id in (select id from (select id,departmentid,salary,
	   @rank:= 
	   case when @last_salary = salary and @last_department = departmentid then @rank
			when @last_salary != salary and @last_department = departmentid then @rank+1 
			when @last_department != departmentid then 1
	   end as row_rank,
	   @last_salary := salary,
	   @last_department := departmentid
from (select id,departmentid,salary,@last_salary:= '', @rank:=0 , @last_department:= ''  
from employee 
order by departmentid,salary desc )a)b
where row_rank <=3);
### 代码

```mysql
# Write your MySQL query statement below

select d.name department,c.name employee,salary
from employee c join department d  on c.departmentid = d.Id 
where c.Id in (select id from (select id,departmentid,salary,
	   @rank:= 
	   case when @last_salary = salary and @last_department = departmentid then @rank
			when @last_salary != salary and @last_department = departmentid then @rank+1 
			when @last_department != departmentid then 1
	   end as row_rank,
	   @last_salary := salary,
	   @last_department := departmentid
from (select id,departmentid,salary,@last_salary:= '', @rank:=0 , @last_department:= ''  
from employee 
order by departmentid,salary desc )a)b
where row_rank <=3);

```