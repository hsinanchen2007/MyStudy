
select 
    ifnull((select distinct salary  
            from employee
            order by salary desc
            limit 1,1),null)
as SecondHighestSalary

# ifnull 是用来避免没有第二个数据
# distinct 是除掉并排数据