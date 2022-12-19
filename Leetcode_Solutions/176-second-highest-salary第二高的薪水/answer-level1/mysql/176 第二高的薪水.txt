### 解题思路
第一次先写出降序；
第二次加入ifnull 和 limit offset ，提交出错；
第三次查看官方的写法，对比自己的代码，发现应该在外层再写一个select查询，并且将内层查询写入ifnull里面，结果符合要求。
总结：一定要仔细审题，考虑题目要求的格式，正确输出。
### 代码

```mysql
# Write your MySQL query statement below
select ifnull((SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),null) SecondHighestSalary

```