### 解题思路
这里主要需要解决排名问题，找到对应排名的列获取其salary，排名相同的值去重即可。
这里使用oracle提供的排名函数效率看起来好一些：dense_rank()  紧密连续排名
oracle 博大精深只是提供一个函数给大家参考下，算不得很有技术含量了

### 代码
```oraclesql
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    select distinct(ee.salary) into result from (select e.salary, dense_rank() over(order by e.salary desc) nth from employee e) ee where ee.nth = N ;
    RETURN result;
END;
```