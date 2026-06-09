一开始忘了去重，
直接写
select  Salary as SecondHighestSalary from Employee order by  Salary desc limit 1,1
输出的结果明明一致，却还是判断错误。这时候想起，如果出现两个一样高的薪水，就不会有第二高的，所以修改成
select (select distinct Salary from Employee order by  Salary desc limit 1, 1) as SecondHighestSalary

limit的用法：
当limit后面跟两个参数的时候，第一个数表示要跳过的数量，后一位表示要取的数量