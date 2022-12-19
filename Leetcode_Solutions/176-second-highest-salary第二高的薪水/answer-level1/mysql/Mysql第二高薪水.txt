开始写的sql是 select Salary as SecondHighestSalary from Employee order by Salary desc limit 1,1编译❌
没有考虑到题目中考察的：不存在，则返回null；应该用ifnull(A,B)函数 若不为空返回A，否则返回B
并且没有考虑到第二高的薪水有重复的情况，用distinct去重
利用order by 倒序和limit[offset,n] -- offset是偏移量，即跳过多少行，n是需要取出的条目