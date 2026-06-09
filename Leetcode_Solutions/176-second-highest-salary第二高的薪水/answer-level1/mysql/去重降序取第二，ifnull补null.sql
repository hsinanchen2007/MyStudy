### 解题思路
1.ifnull函数：ifnull(v1,v2)是指如果v1为null，则返回v2的值
2.不同的员工可能有相同的薪水，用distinct去重，再用limit1,1在最高薪之后取一个，即为第二高薪

### 代码

```mysql
select ifnull((select distinct Salary from Employee 
order by Salary desc limit 1,1), null) SecondHighestSalary;
```