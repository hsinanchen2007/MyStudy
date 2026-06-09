### 解题思路
1.按薪水进行逆序排序,dense_rank 函数可进行编码
2.找出需要对应的行 
3.进行空值判断
4.如果要求相同薪水顺延 可以使用row_number 函数
4.如果要求相同薪水并列 可以使用rank 函数

### 代码

```oraclesql
select  nvl(
          (select distinct b.Salary from (
select a.*, dense_rank() over(order by a.Salary  desc) as rn
                     from Employee  a ) b where b.rn =2),null ) SecondHighestSalary  from dual
```

