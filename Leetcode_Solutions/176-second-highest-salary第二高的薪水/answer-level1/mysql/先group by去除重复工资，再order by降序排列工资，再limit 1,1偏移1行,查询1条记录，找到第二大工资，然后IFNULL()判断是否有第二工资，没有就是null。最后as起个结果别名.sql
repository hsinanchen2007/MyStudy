### 解题思路
先group by去除重复工资，再order by降序排列工资，再limit 1,1偏移1行,查询1条记录，找到第二大工资，然后IFNULL()判断是否有第二工资，没有就是null。最后as起个结果别名

### 代码

```mysql
# Write your MySQL query statement below

select IFNULL((select Salary from Employee group by Salary order by Salary desc limit 1,1),NULL)as SecondHighestSalary
```