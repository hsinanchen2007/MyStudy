### 解题思路
1.找第2高薪水，所以首先去除最高的薪水，从剩下的元组中找最高的薪水。
Salary < some (select Salary from Employee) 得到除了最高的薪水的元组
Salary >= all(select Salary from Employee where Salary < some (select Salary from Employee))
找到这些薪水中最高的
2.因为可能不止一个，需要去重，使用distinct
3.若薪水全部一样则返回null ，使用IFNULL(a,b) 如果a为空或者null则输出b

### 代码

```mysql
# Write your MySQL query statement below
# 等价于查找，除了最高薪水的元组 中最高薪水的元组
# null问题，若薪水都一样，则不存在最高薪水，使用IFNULL(a,b) 如果a为空或者null则输出b
# 当有多个第二高薪水使用distinct除去重复的
select ifnull( 
( select distinct Salary SecondHighestSalary from Employee where Salary < some (select Salary from Employee) and Salary >= all(select Salary from Employee where Salary < some (select Salary from Employee)) ) ,
null) AS SecondHighestSalary


```