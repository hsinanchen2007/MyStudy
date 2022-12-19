### 解题思路
注意：null 表示什么也不是， 不能= > <  所有的判断，结果都是false，所有只能用 is null进行判断。
### 代码

```mysql
# Write your MySQL query statement below
select e.name,b.bonus
from Employee e 
left join Bonus b on e.empId=b.empId 
where  b.bonus is null or b.bonus<1000 ;

```