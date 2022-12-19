
执行结果：通过
执行用时 :670 ms, 在所有 Oracle 提交中击败了96.10%的用户
内存消耗 :N/A
背景:   初学
没有找到oracle合适的答案,献丑献丑
select SALARY SecondHighestSalary from 
(
	select SALARY from 
	(
		select salary ,rownum rn
			from (select distinct( salary) from employee order by SALARY desc)
	)	t	
	where t.rn = 2 
	union all select null from dual 
)
where rownum = 1
