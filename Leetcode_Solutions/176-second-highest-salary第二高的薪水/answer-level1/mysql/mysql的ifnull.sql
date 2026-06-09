### 解题思路
此处撰写解题思路
首先用where + max函数去掉最高值，使用isnull给剩下内容的最高值一个返回值并为其命名。

### 代码

```mysql
# Write your MySQL query statement below
select IFNULL(max(Salary),null) as SecondHighestSalary  
    from Employee where Salary != (select max(Salary) from Employee)
```