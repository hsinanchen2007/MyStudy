### 解题思路
1.考虑 N<1 的情况；
  考虑 N>count(dinsctinct salary) 的情况。
用**ifnull()函数**解决任意数N导致salary不存在的情况
2.Mysql有两种方法可以解决排名问题
**方法一：limit a,b
方法二：limit a offset b**
两种方法用法详情：https://www.cnblogs.com/songtzh/p/12044489.html
### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    # 定义变量
    declare p int;
    # 变量赋值
    set p=n-1;
RETURN (      
        select ifnull(
                        (
                        # LIMIT a OFFSET b 方法  
                        #select distinct salary from employee order by salary desc limit 1 OFFSET P

                        # LIMIT a,b 方法
                        select distinct salary from employee order by salary desc limit P,1
                        ),null) as SecondHighestSalary 
        );     
END
```
执行结果：通过
显示详情 
**执行用时 :133 ms, 在所有 mysql 提交中击败了99.83%的用户**
内存消耗 :0B, 在所有 mysql 提交中击败了100.00%的用户