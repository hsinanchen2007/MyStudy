### 解题思路
1.将表中的所有数据过滤去重(distinct)
2.将过滤后数据按照金额进行降序排列(order by salary asc  )，取第二行数据（limit 1,1 ）
3.使用ifnull函数进行判断查询的数据是否是null,如果是null,则返回null （ifnull( exp ,null )）

### 代码

```mysql
# Write your MySQL query statement below
select  ifnull( (select distinct(salary) from employee order by salary desc limit 1,1)  , null ) as  SecondHighestSalary ;



```