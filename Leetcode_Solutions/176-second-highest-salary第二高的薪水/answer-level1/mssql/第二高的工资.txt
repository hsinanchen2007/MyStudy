### 解题思路
查找第二高的情况，分解法，分为理想状态和非理想状态，采用union处理；
对于理想情况下，找到max，再用max的去匹配第二高的元素，很容易找到，此处就不叙述了。重点是 非理想的情况，比如数据表只有1行数据，2行一样的数据。这时候，就需要考虑。我的关键处理是判断是否小于最高值的元素的个数有没有小于1的。如有小于1了，就是null。

### 代码

```mssql
/* Write your T-SQL query statement below */


select isnull(SecondHighestSalary,null) SecondHighestSalary from 
(select top 1  Salary as SecondHighestSalary from  Employee where Salary<(select max(Salary) from  Employee)
order by Salary desc ) s
union  
select null as SecondHighestSalary from  Employee
where (
1>(select count(1) from  Employee where Salary <(select max(Salary) from Employee)  )
)



```