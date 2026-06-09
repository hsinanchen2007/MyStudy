### 解题思路
ifnull(a, b)如果a非空则a，否则b；a为查询第二高的Salary语句，**按降序排列**；若a查不到，则b为null
select ifnull(a, b) **as SecondHighestSalary** 
limit限制输出个数
offset设置忽略的个数
limit和offset放在order by后面

### 代码

```mysql
# Write your MySQL query statement below
select 
ifnull
((select distinct Salary from Employee order by Salary desc limit 1 offset 1), null) as SecondHighestSalary;
```